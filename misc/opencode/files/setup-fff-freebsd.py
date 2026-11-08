#!/usr/bin/env python3
"""Make OpenCode's bundled @ff-labs/fff-bun work on FreeBSD.

Upstream ships no FreeBSD `@ff-labs/fff-bin-*` package, so @ff-labs/fff-bun
cannot embed a native library there and OpenCode's `fff` file finder stays
unavailable.  This mirrors what the Linux/macOS/Windows branches do:

  1. Create the platform package @ff-labs/fff-bin-freebsd-<arch> holding the
     libfff_c.so built from fff's Rust source (crates/fff-c), so that
     `bun build --compile` embeds the shared object into the binary.
  2. Patch @ff-labs/fff-bun's embedded.ts so the native-asset loader resolves
     that package when `process.platform === "freebsd"`.

Usage:
  setup-fff-freebsd.py <opencode-root> <path-to-libfff_c.so> <version> <arch>

Where <arch> is "x64" or "arm64" (the Node/Bun arch tag, matching process.arch),
and <opencode-root> is the checked-out opencode source tree (the directory
containing node_modules/).
"""
import os
import re
import shutil
import sys

# The end of embedded.ts's resolveEmbeddedLibPath(), just before the module
# resolves embeddedLibPath.  We insert the FreeBSD branch ahead of `return null`.
ANCHOR = "  return null;\n}\n\n// Resolved once at module init"

BRANCH = """  if (process.platform === "freebsd") {
    return importFile(
      import(`@ff-labs/fff-bin-freebsd-${process.arch}/libfff_c.so`, {
        with: { type: "file" },
      }),
    );
  }

  return null;
}

// Resolved once at module init"""

PKG_JSON = """{
  "name": "@ff-labs/fff-bin-freebsd-%ARCH%",
  "version": "%VERSION%",
  "description": "Prebuilt freebsd-%ARCH% native library for @ff-labs/fff-bun",
  "os": ["freebsd"],
  "cpu": ["%ARCH%"]
}
"""


def find_fff_bun(root: str) -> str:
    # Hoisted layout: node_modules/@ff-labs/fff-bun
    direct = os.path.join(root, "node_modules", "@ff-labs", "fff-bun")
    if os.path.exists(os.path.join(direct, "src", "embedded.ts")):
        return os.path.realpath(direct)
    # bun's isolated layout: node_modules/.bun/@ff-labs+fff-bun@<ver>/node_modules/@ff-labs/fff-bun
    base = os.path.join(root, "node_modules", ".bun")
    if os.path.isdir(base):
        for name in sorted(os.listdir(base)):
            if name.startswith("@ff-labs+fff-bun@"):
                pkg = os.path.join(base, name, "node_modules", "@ff-labs", "fff-bun")
                if os.path.exists(os.path.join(pkg, "src", "embedded.ts")):
                    return pkg
    raise SystemExit(f"@ff-labs/fff-bun not found under {root}/node_modules")


def patch_embedded(pkg: str) -> None:
    path = os.path.join(pkg, "src", "embedded.ts")
    if not os.path.exists(path):
        raise SystemExit(f"embedded.ts not found: {path}")
    src = open(path, encoding="utf-8").read()
    if 'process.platform === "freebsd"' in src:
        print("  - embedded.ts already patched")
        return
    if ANCHOR not in src:
        raise SystemExit(f"expected anchor not found in {path}")
    src = src.replace(ANCHOR, BRANCH, 1)
    open(path, "w", encoding="utf-8").write(src)
    print("  - patched embedded.ts")


def create_platform_package(root: str, lib: str, version: str, arch: str) -> str:
    dest = os.path.join(root, "node_modules", "@ff-labs", f"fff-bin-freebsd-{arch}")
    os.makedirs(dest, exist_ok=True)
    shutil.copyfile(lib, os.path.join(dest, "libfff_c.so"))
    open(os.path.join(dest, "package.json"), "w", encoding="utf-8").write(
        PKG_JSON.replace("%VERSION%", version).replace("%ARCH%", arch)
    )
    return dest


def main() -> int:
    root = sys.argv[1]
    lib = sys.argv[2]
    version = sys.argv[3] if len(sys.argv) > 3 else "0.10.5"
    arch = sys.argv[4] if len(sys.argv) > 4 else "arm64"
    if arch not in ("x64", "arm64"):
        raise SystemExit(f"unsupported arch tag: {arch}")
    pkg = find_fff_bun(root)
    print(f"fff-bun: {pkg}")
    patch_embedded(pkg)
    dest = create_platform_package(root, lib, version, arch)
    print(f"platform package: {dest}")
    for name in ("package.json", "libfff_c.so"):
        p = os.path.join(dest, name)
        print(f"  {name}: {os.path.getsize(p)} bytes")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
