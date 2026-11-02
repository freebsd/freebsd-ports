PORTNAME=	stalwart-migrate
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
CATEGORIES=	mail

MAINTAINER=	jsi@jules.de
COMMENT=	Migrate Stalwart Mail Server data stores from v0.16 to v1
WWW=		https://github.com/stalwartlabs/stalwart-migrate

LICENSE=		AGPLv3 SELv2
LICENSE_COMB=		dual
LICENSE_NAME_SELv2=	Stalwart Enterprise License 2.0
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_SELv2=	${WRKSRC}/LICENSES/LicenseRef-SEL.txt
LICENSE_PERMS_SELv2=	pkg-mirror auto-accept

DEPRECATED=	Stalwart 0.16 is end-of-life; only needed while migrating to Stalwart 1.x
EXPIRATION_DATE=	2027-11-02
BROKEN_i386=	rustc-LLVM ERROR: out of memory

# aws-lc-sys has no pregenerated bindings for FreeBSD and runs bindgen
BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli
LIB_DEPENDS=	libzstd.so:archivers/zstd
# The test crates enable RocksDB regardless of the ROCKSDB option
TEST_DEPENDS=	${LOCALBASE}/lib/librocksdb.so:databases/rocksdb

USES=		cargo llvm:build,noexport sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs

SUB_FILES=	pkg-message

# rusqlite is built with the "bundled" feature; link databases/sqlite3
# instead.  librocksdb-sys runs bindgen on the databases/rocksdb headers.
CARGO_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		LIBSQLITE3_SYS_USE_PKG_CONFIG=1 \
		ROCKSDB_INCLUDE_DIR=${LOCALBASE}/include
CARGO_FEATURES=	--no-default-features
CARGO_INSTALL_PATH=	crates/migrate

PLIST_FILES=	bin/stalwart-migrate
PORTDOCS=	CHANGELOG.md README.md SCHEMA_CHANGES.md

OPTIONS_DEFINE=		CLI_PLAN DOCS ENTERPRISE
OPTIONS_DEFAULT=	MYSQL POSTGRES REDIS ROCKSDB S3 SQLITE
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	AZURE MYSQL POSTGRES REDIS ROCKSDB S3 SQLITE
OPTIONS_EXCLUDE_armv6=	ROCKSDB
OPTIONS_EXCLUDE_armv7=	ROCKSDB
OPTIONS_EXCLUDE_i386=	ROCKSDB
OPTIONS_EXCLUDE_powerpc=	ROCKSDB

BACKENDS_DESC=		Database and storage backends
AZURE_DESC=		Azure Blob Storage backend
CLI_PLAN_DESC=		Script to convert stalwart-cli plans to the v1 schema
ENTERPRISE_DESC=	Enterprise features (must match the Stalwart v1 build)
MYSQL_DESC=		MySQL backend
POSTGRES_DESC=		PostgreSQL backend
REDIS_DESC=		Redis backend
ROCKSDB_DESC=		RocksDB backend
S3_DESC=		S3 storage backend
SQLITE_DESC=		SQLite backend

AZURE_VARS=		CARGO_FEATURES+=azure
CLI_PLAN_USES=		python:3.11+,run shebangfix
CLI_PLAN_VARS=		SHEBANG_FILES=cli-plan/convert_plan.py
CLI_PLAN_PLIST_FILES=	bin/stalwart-migrate-convert-plan \
			${DATADIR_REL}/cli-plan/convert_plan.py \
			${DATADIR_REL}/mapping/normalize_016x.toml \
			${DATADIR_REL}/mapping/prompts.toml \
			${DATADIR_REL}/mapping/schema/v0.16.27.json.gz \
			${DATADIR_REL}/mapping/schema/v1.json.gz \
			${DATADIR_REL}/mapping/schema/v1_oss.json.gz \
			${DATADIR_REL}/mapping/v016_to_v1.toml
ENTERPRISE_VARS=	CARGO_FEATURES+=enterprise
MYSQL_VARS=		CARGO_FEATURES+=mysql
POSTGRES_VARS=		CARGO_FEATURES+=postgres
REDIS_VARS=		CARGO_FEATURES+=redis
ROCKSDB_LIB_DEPENDS=	librocksdb.so:databases/rocksdb
ROCKSDB_VARS=		CARGO_FEATURES+=rocks
S3_VARS=		CARGO_FEATURES+=s3
SQLITE_VARS=		CARGO_FEATURES+=sqlite

# librocksdb-sys comes from a git snapshot without the bundled RocksDB
# submodule.  Its build script runs "git submodule update" unless it
# finds rocksdb/AUTHORS; the port links against databases/rocksdb, so
# the bundled sources are not needed.
post-patch:
	@${MKDIR} ${WRKSRC_crate_librocksdb-sys}/librocksdb-sys/rocksdb
	@${TOUCH} ${WRKSRC_crate_librocksdb-sys}/librocksdb-sys/rocksdb/AUTHORS

post-install-CLI_PLAN-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/cli-plan ${STAGEDIR}${DATADIR}/mapping/schema
	${INSTALL_SCRIPT} ${WRKSRC}/cli-plan/convert_plan.py \
		${STAGEDIR}${DATADIR}/cli-plan
	${INSTALL_DATA} ${WRKSRC}/mapping/normalize_016x.toml \
		${WRKSRC}/mapping/prompts.toml \
		${WRKSRC}/mapping/v016_to_v1.toml ${STAGEDIR}${DATADIR}/mapping
	${INSTALL_DATA} ${WRKSRC}/mapping/schema/*.json.gz \
		${STAGEDIR}${DATADIR}/mapping/schema
	${RLN} ${STAGEDIR}${DATADIR}/cli-plan/convert_plan.py \
		${STAGEDIR}${PREFIX}/bin/stalwart-migrate-convert-plan

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
