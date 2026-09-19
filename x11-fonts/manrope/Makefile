PORTNAME=	manrope
DISTVERSION=	4.505
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Modern geometric sans-serif font
WWW=		https://www.gent.media/manrope

LICENSE=	OFL11

USES=		fonts
FONTNAME=	Manrope
USE_GITHUB=	yes
GH_ACCOUNT=	googlefonts
GH_TAGNAME=	468c0dbe38efa331b80bfe9448256abe27be44c3

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/otf/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/webfonts/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/variable/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
