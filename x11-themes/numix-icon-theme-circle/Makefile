PORTNAME=	numix-icon-theme-circle
DISTVERSION=	22.04.06
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Icon theme from the Numix project

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	numixproject
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} Numix-Circle ${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>
