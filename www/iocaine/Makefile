PORTNAME=	iocaine
DISTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://git.madhouse-project.org/iocaine/iocaine/archive/ \
		https://raw.githubusercontent.com/ai-robots-txt/ai.robots.txt/refs/tags/v${ROBOTS_VERSION}/:robots \
		https://fennel-lang.org/downloads/:fennel
DISTFILES+=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		robots.json:robots \
		fennel-${FENNEL_VERSION}.lua:fennel
EXTRACT_ONLY=	${_DISTFILES:M*${EXTRACT_SUFX}} \
		${_DISTFILES:M*crate}

MAINTAINER=	sko@rostwald.de
COMMENT=	Deadliest poison known to AI
WWW=		https://iocaine.madhouse-project.org \
		https://git.madhouse-project.org/iocaine/iocaine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libzstd.so:archivers/zstd

USES=		cargo gmake
USE_RC_SUBR=	iocaine

ROBOTS_VERSION=	1.45
FENNEL_VERSION=	1.6.1

CARGO_BUILD_ARGS+=	'--no-default-features'
CARGO_VENDOR_DIR=	${WRKDIR}/cargo-crates

TEST_TARGET=	test

IOCAINE_USER?=		www
IOCAINE_GROUP?=		www
IOCAINE_DATADIR=	${ETCDIR}

SUB_FILES=	pkg-message
SUB_LIST=	IOCAINE_DATADIR=${IOCAINE_DATADIR} \
		IOCAINE_GROUP=${IOCAINE_GROUP} \
		IOCAINE_USER=${IOCAINE_USER}

USERS=		${IOCAINE_USER}
GROUPS=		${IOCAINE_GROUP}

PLIST_SUB=	GROUPS=${GROUPS} \
		USERS=${USERS}

post-extract:
	${MV} ${WRKDIR}/${PORTNAME} \
		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-patch:
	${REINPLACE_CMD} 's|%%ETCDIR%%|${ETCDIR}|g' \
		${WRKSRC}/iocaine-powder/embeds/defaults/config.kdl

pre-build:
	@${MKDIR} ${WRKSRC}/iocaine-powder/embeds/defaults/etc/
	@${CP} ${DISTDIR}/robots.json ${WRKSRC}/iocaine-powder/embeds/defaults/etc/
	@${CP} ${DISTDIR}/fennel-${FENNEL_VERSION}.lua ${WRKSRC}/iocaine-powder/embeds/defaults/etc/fennel.lua

do-install:
# workaround for error: found a virtual manifest at `xx` instead of a package manifest
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/iocaine \
		${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/iocaine-powder/embeds/defaults && \
		${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR})
	${INSTALL_DATA} ${WRKSRC}/iocaine-powder/embeds/defaults/config.kdl \
		${STAGEDIR}${ETCDIR}/config.kdl.sample
	${INSTALL_DATA} ${WRKSRC}/iocaine-powder/embeds/defaults/testsuite.kdl \
		${STAGEDIR}${ETCDIR}/testsuite.kdl.sample
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>
