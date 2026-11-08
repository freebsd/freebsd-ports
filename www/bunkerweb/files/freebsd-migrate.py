"""Bring the BunkerWeb database schema up to the installed version.

Upstream runs the migration from its systemd wrapper, which FreeBSD does not
use, so the scheduler rc script calls this script before starting.
"""

from os import environ
from pathlib import Path
from subprocess import run
from sys import executable, exit, stderr

import sqlalchemy as sa

ALEMBIC = Path(__file__).resolve().parent / "alembic"
DATADIR = Path(__file__).resolve().parents[2]
INI = Path("/var/lib/bunkerweb/alembic.ini")
URI = environ.get("DATABASE_URI") or "sqlite:////var/lib/bunkerweb/db.sqlite3"


def alembic(*args):
    return run([executable, "-m", "alembic", "-c", str(INI), *args], cwd=ALEMBIC, capture_output=True, text=True)


def main():
    installed = (DATADIR / "VERSION").read_text().strip()
    engine = sa.create_engine(URI)
    tables = sa.inspect(engine).get_table_names()
    if "bw_metadata" not in tables:
        return 0

    with engine.connect() as conn:
        rows = conn.execute(sa.text("SELECT version FROM bw_metadata WHERE id = 1"))
        current = next(iter(rows))[0]
    if current in (installed, "dev", "testing"):
        return 0

    dbtype = URI.split(":", 1)[0].split("+", 1)[0]
    INI.parent.mkdir(parents=True, exist_ok=True)
    lines = []
    for line in (ALEMBIC / "alembic.ini").read_text().splitlines():
        if line.startswith("version_locations"):
            line = "version_locations = " + dbtype + "_versions"
        lines.append(line)
    INI.write_text(chr(10).join(lines) + chr(10))

    if "alembic_version" not in tables:
        normalized = current.replace(".", "_").replace("-", "_").replace("~", "_")
        pattern = "*_upgrade_to_version_" + normalized + ".py"
        matches = sorted((ALEMBIC / (dbtype + "_versions")).glob(pattern))
        if not matches:
            print("no migration file for database version " + current, file=stderr)
            return 1
        stamped = alembic("stamp", matches[0].name.split("_", 1)[0])
        if stamped.returncode != 0:
            print(stamped.stderr.strip(), file=stderr)
            return 1

    upgraded = alembic("upgrade", "head")
    if upgraded.returncode != 0:
        print(upgraded.stderr.strip(), file=stderr)
        return 1

    print("database migrated from " + current + " to " + installed)
    return 0


exit(main())
