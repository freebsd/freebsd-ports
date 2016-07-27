# Created by: arrowdodger <6yearold@gmail.com>
# $FreeBSD$

PORTNAME=	hasklig
PORTVERSION=	0.9
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/i-tu/Hasklig/releases/download/${PORTVERSION}/
DISTNAME=	Hasklig-${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	Haskell code font with monospaced ligatures

USES=		fonts zip
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
