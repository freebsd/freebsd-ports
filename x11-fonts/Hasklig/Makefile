# Created by: arrowd <6yearold@gmail.com>
# $FreeBSD$

PORTNAME=	Hasklig
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/i-tu/Hasklig/releases/download/${PORTVERSION}/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Haskell code font with monospaced ligatures

LICENSE=	OFL11

USES=		fonts zip
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
