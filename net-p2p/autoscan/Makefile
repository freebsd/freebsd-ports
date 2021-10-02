PORTNAME=	autoscan
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	net-p2p linux
MASTER_SITES=	https://github.com/Cloudbox/autoscan/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}_linux_amd64
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Scan Plex library on webhook triggers

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

USES=		linux
USE_RC_SUBR=	autoscan

CONFLICTS_INSTALL=	autoconf-wrapper

NO_BUILD=	yes
SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

NO_WRKSUBDIR=	yes

USERS=		autoscan
GROUPS=		autoscan

PLIST_FILES=	bin/autoscan

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
