# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	win98se-icon-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.13
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Enhanced Classic Win98SE icon theme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	nestoris
GH_PROJECT=	Win98SE
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} SE98 ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>
