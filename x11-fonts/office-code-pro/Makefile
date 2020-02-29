# $FreeBSD$

PORTNAME=	office-code-pro
DISTVERSION=	1.004
CATEGORIES=	x11-fonts

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Customized version of the Source Code Pro font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	nathco
GH_PROJECT=	Office-Code-Pro

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Fonts/*/TTF/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
