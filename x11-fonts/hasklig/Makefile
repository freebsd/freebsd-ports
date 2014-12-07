# Created by: arrowdodger <6yearold@gmail.com>
# $FreeBSD$

PORTNAME=	hasklig
PORTVERSION=	0.4
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/i-tu/Hasklig/releases/download/${PORTVERSION}/
DISTNAME=	Hasklig-${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	Haskell code font with monospaced ligatures

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
NO_BUILD=	yes

NO_ARCH=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
