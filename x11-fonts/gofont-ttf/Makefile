PORTNAME=	gofont-ttf
DISTVERSION=	g20231220
CATEGORIES=	x11-fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Go font family
WWW=		https://blog.golang.org/go-fonts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/font/gofont/ttfs/README

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	image
GH_TAGNAME=	9e190ae

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/font/gofont/ttfs/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
