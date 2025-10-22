PORTNAME=	stalwart
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.4
CATEGORIES=	mail

MAINTAINER=	orville@anislet.dev
COMMENT=	Stalwart Mail Server
WWW=		https://stalw.art/

LICENSE=		AGPLv3 SELv1
LICENSE_COMB=		multi
LICENSE_NAME_SELv1=	Stalwart Enterprise License 1.0
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_SELv1=	${WRKSRC}/LICENSES/LicenseRef-SEL.txt
LICENSE_PERMS_SELv1=	pkg-mirror auto-accept

NOT_FOR_ARCHS=		powerpc powerpc64 powerpc64le riscv64
NOT_FOR_ARCHS_REASON=	ring-v0.16.20 does not support this arch.

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cpe cargo
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs
GH_PROJECT=	stalwart
USE_RC_SUBR=	stalwart

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

CARGO_FEATURES=	--no-default-features

CARGO_INSTALL_PATH=	crates/main crates/cli

OPTIONS_DEFINE=		ENTERPRISE
OPTIONS_DEFAULT=	SQLITE POSTGRES MYSQL ROCKSDB S3 REDIS
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	SQLITE FOUNDATIONDB POSTGRES MYSQL ROCKSDB ELASTIC S3 REDIS AZURE
OPTIONS_EXCLUDE_powerpc=	ROCKSDB
OPTIONS_EXCLUDE_armv6=	ROCKSDB
OPTIONS_EXCLUDE_armv7=	ROCKSDB
OPTIONS_EXCLUDE_i386=	ROCKSDB

BACKEND_DESC=		Database and storage backends
AZURE_DESC=		Enable Azure storage backend
ELASTIC_DESC=		Enable ElasticSearch backend
ENTERPRISE_DESC=	Enable Enterprise features (require license)
FOUNDATIONDB_DESC=	Enable FoundationDB backend
MYSQL_DESC=		Enable MySQL backend
POSTGRES_DESC=		Enable PostgreSQL backend
REDIS_DESC=		Enable Redis backend
ROCKSDB_DESC=		Enable RocksDB backend
S3_DESC=		Enable S3 storage backend
SQLITE_DESC=		Enable SQLite backend

AZURE_VARS=		CARGO_FEATURES+=azure
ELASTIC_VARS=		CARGO_FEATURES+=elastic
ENTERPRISE_VARS=	CARGO_FEATURES+=enterprise
FOUNDATIONDB_LIB_DEPENDS=		libfdb_c.so:databases/foundationdb73-client
FOUNDATIONDB_VARS=	CARGO_FEATURES+=foundationdb
MYSQL_VARS=		CARGO_FEATURES+=mysql
POSTGRES_VARS=		CARGO_FEATURES+=postgres
REDIS_VARS=		CARGO_FEATURES+=redis
ROCKSDB_BUILD_DEPENDS=	${LOCALBASE}/llvm21/lib/libclang.so:devel/llvm21
ROCKSDB_LIB_DEPENDS=	librocksdb.so:databases/rocksdb
ROCKSDB_VARS=		CARGO_FEATURES+=rocks
S3_VARS=		CARGO_FEATURES+=s3
SQLITE_VARS=		CARGO_FEATURES+=sqlite

.include <bsd.port.options.mk>

USERS=	stalwart
GROUPS=	stalwart

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/resources/config/config.toml \
		${STAGEDIR}${ETCDIR}/config.toml.sample

	@${MKDIR} ${STAGEDIR}/var/db/stalwart
	@${MKDIR} ${STAGEDIR}/var/db/stalwart/data

.include <bsd.port.mk>
