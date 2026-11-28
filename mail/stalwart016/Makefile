PORTNAME=	stalwart
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.27
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	016

MAINTAINER=	jsi@jules.de
COMMENT=	Stalwart Mail Server
WWW=		https://stalw.art/

# The source distfile always contains code under the Stalwart Enterprise
# License, which does not permit redistribution, so it must not be mirrored.
# Without ENTERPRISE that code is stripped before the build (see
# post-patch-ENTERPRISE-off), so the package may be.
LICENSE=		AGPLv3 SELv2
LICENSE_COMB=		multi
LICENSE_NAME_SELv2=	Stalwart Enterprise License 2.0
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_SELv2=	${WRKSRC}/LICENSES/LicenseRef-SEL.txt
LICENSE_DISTFILES_SELv2=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_PERMS_SELv2=	pkg-mirror auto-accept

DEPRECATED=	Stalwart 0.16 is end-of-life; migrate to Stalwart 1.x
EXPIRATION_DATE=	2027-11-02
BROKEN_i386=	rustc-LLVM ERROR: out of memory

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cpe cargo
CPE_VENDOR=	stalw
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs
USE_RC_SUBR=	stalwart

CONFLICTS_INSTALL=	stalwart

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

CARGO_FEATURES=	--no-default-features

CARGO_INSTALL_PATH=	crates/main

OPTIONS_DEFINE=		ENTERPRISE
OPTIONS_DEFAULT=	SQLITE POSTGRES MYSQL ROCKSDB S3 REDIS
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	SQLITE FOUNDATIONDB POSTGRES MYSQL ROCKSDB ELASTIC S3 REDIS AZURE
OPTIONS_EXCLUDE_powerpc=	ROCKSDB
OPTIONS_EXCLUDE_armv6=	ROCKSDB
OPTIONS_EXCLUDE_armv7=	ROCKSDB
OPTIONS_EXCLUDE_i386=	ROCKSDB

BACKENDS_DESC=		Database and storage backends
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
ELASTIC_BROKEN=		none of the selected packages contains this feature
ENTERPRISE_USES_OFF=	python:patch,env
ENTERPRISE_VARS=	CARGO_FEATURES+=enterprise \
			LICENSE_PERMS_SELv2=none
FOUNDATIONDB_LIB_DEPENDS=		libfdb_c.so:databases/foundationdb73-client
FOUNDATIONDB_VARS=	CARGO_FEATURES+=foundationdb
MYSQL_VARS=		CARGO_FEATURES+=mysql
POSTGRES_VARS=		CARGO_FEATURES+=postgres
REDIS_VARS=		CARGO_FEATURES+=redis
ROCKSDB_LIB_DEPENDS=	librocksdb.so:databases/rocksdb
ROCKSDB_USES=		llvm:21
ROCKSDB_VARS=		CARGO_FEATURES+=rocks
S3_VARS=		CARGO_FEATURES+=s3
SQLITE_VARS=		CARGO_FEATURES+=sqlite

.include <bsd.port.options.mk>

USERS=	stalwart
GROUPS=	stalwart

# The stalwartlabs/opentelemetry-rust fork was deleted upstream; the pinned
# commit is still available from the parent repository.
post-patch:
	@${REINPLACE_CMD} 's|stalwartlabs/opentelemetry-rust|open-telemetry/opentelemetry-rust|' \
		${WRKSRC}/Cargo.lock ${WRKSRC}/crates/common/Cargo.toml

# Strip the code under the Stalwart Enterprise License (whole files and
# SPDX-tagged snippets) with upstream's own script, so that the resulting
# binary is AGPLv3 only.
post-patch-ENTERPRISE-off:
	@${PYTHON_CMD} ${WRKSRC}/resources/scripts/ossify.py ${WRKSRC}/crates

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}/var/db/stalwart
	@${MKDIR} ${STAGEDIR}/var/db/stalwart/data
	@${MKDIR} ${STAGEDIR}/var/log/stalwart

.include <bsd.port.mk>
