PORTNAME=	stalwart
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	mail

MAINTAINER=	orville@anislet.dev
COMMENT=	Stalwart Mail Server
WWW=		https://stalw.art/

LICENSE=		AGPLv3 SELv2
LICENSE_COMB=		multi
LICENSE_NAME_SELv2=	Stalwart Enterprise License 2.0
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_SELv2=	${WRKSRC}/LICENSES/LicenseRef-SEL.txt
LICENSE_PERMS_SELv2=	pkg-mirror auto-accept

BROKEN_i386=	rustc-LLVM ERROR: out of memory

BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cpe cargo llvm:build,noexport
CPE_VENDOR=	stalw
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs
USE_RC_SUBR=	stalwart

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

CARGO_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		ROCKSDB_INCLUDE_DIR=${LOCALBASE}/include
CARGO_FEATURES=	--no-default-features

CARGO_INSTALL_PATH=	crates/main

OPTIONS_DEFINE=		ENTERPRISE
OPTIONS_DEFAULT=	SQLITE POSTGRES MYSQL ROCKSDB S3 REDIS
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	SQLITE POSTGRES MYSQL ROCKSDB S3 REDIS AZURE
OPTIONS_EXCLUDE_powerpc=	ROCKSDB
OPTIONS_EXCLUDE_armv6=	ROCKSDB
OPTIONS_EXCLUDE_armv7=	ROCKSDB
OPTIONS_EXCLUDE_i386=	ROCKSDB

BACKENDS_DESC=		Database and storage backends
AZURE_DESC=		Enable Azure storage backend
ENTERPRISE_DESC=	Enable Enterprise features (require license)
MYSQL_DESC=		Enable MySQL backend
POSTGRES_DESC=		Enable PostgreSQL backend
REDIS_DESC=		Enable Redis backend
ROCKSDB_DESC=		Enable RocksDB backend
S3_DESC=		Enable S3 storage backend
SQLITE_DESC=		Enable SQLite backend

AZURE_VARS=		CARGO_FEATURES+=azure
ENTERPRISE_VARS=	CARGO_FEATURES+=enterprise
MYSQL_VARS=		CARGO_FEATURES+=mysql
POSTGRES_VARS=		CARGO_FEATURES+=postgres
REDIS_VARS=		CARGO_FEATURES+=redis
ROCKSDB_LIB_DEPENDS=	librocksdb.so:databases/rocksdb
ROCKSDB_VARS=		CARGO_FEATURES+=rocks
S3_VARS=		CARGO_FEATURES+=s3
SQLITE_VARS=		CARGO_FEATURES+=sqlite

.include <bsd.port.options.mk>

USERS=	stalwart
GROUPS=	stalwart

# librocksdb-sys comes from a git snapshot without the bundled RocksDB
# submodule.  Its build script runs "git submodule update" unless it finds
# rocksdb/AUTHORS; the port links the system librocksdb instead.
post-patch:
	@${MKDIR} ${WRKSRC_crate_librocksdb-sys}/librocksdb-sys/rocksdb
	@${TOUCH} ${WRKSRC_crate_librocksdb-sys}/librocksdb-sys/rocksdb/AUTHORS

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}/var/db/stalwart
	@${MKDIR} ${STAGEDIR}/var/db/stalwart/data
	@${MKDIR} ${STAGEDIR}/var/log/stalwart

.include <bsd.port.mk>
