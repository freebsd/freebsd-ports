PORTNAME=	rustfs
DISTVERSION=	1.0.4
CATEGORIES=	www
MASTER_SITES=	https://github.com/rustfs/console/releases/download/v${CONSOLE_VERSION}/:console
DISTFILES=	rustfs-console-v${CONSOLE_VERSION}.zip:console
EXTRACT_ONLY=	${DISTFILES:N*\:console:C/:.*$//}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	High-performance distributed S3-compatible object storage
WWW=		https://rustfs.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo cmake:indirect
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

CONSOLE_VERSION=	0.1.37

# install the built binaries directly; cargo install would rebuild them
CARGO_BUILD_ARGS=	--package rustfs
CARGO_INSTALL=		no
CARGO_ENV=		RUSTFS_BUILD_VERSION=${DISTVERSION}

SUB_FILES=	pkg-message
SUB_LIST=	DBDIR=${DBDIR} GROUP=${GROUPS} USER=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB=	DBDIR=${DBDIR} GROUP=${GROUPS} USER=${USERS}

DBDIR=		/var/db/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/rustfs/static
	@${UNZIP_NATIVE_CMD} -oq ${DISTDIR}/rustfs-console-v${CONSOLE_VERSION}.zip \
		-d ${WRKSRC}/rustfs/static

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/rustfs \
		${CARGO_TARGET_DIR}/release/rustfs-cli ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DBDIR}

.include "Makefile.crates"

.include <bsd.port.mk>
