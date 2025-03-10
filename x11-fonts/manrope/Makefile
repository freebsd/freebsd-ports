PORTNAME=	manrope
DISTVERSION=	4.20211221
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.gent.media/assets/manrope/
DISTNAME=	manrope

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Modern geometric sans-serif font
WWW=		https://www.gent.media/manrope

LICENSE=	OFL11

USES=		fonts zip
FONTNAME=	Manrope

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/otf/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/webfonts/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/variable/* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
