# $FreeBSD$

PORTNAME=	gofont-ttf
DISTVERSION=	g20180511
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Go font family

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/font/gofont/ttfs/README

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	image
GH_TAGNAME=	f315e440302883054d0c2bd85486878cb4f8572c

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/font/gofont/ttfs/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
