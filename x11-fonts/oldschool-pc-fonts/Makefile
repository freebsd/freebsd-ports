PORTNAME=	oldschool-pc-fonts
DISTVERSION=	2.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://int10h.org/${PORTNAME}/download/
DISTNAME=	oldschool_pc_font_pack_v${DISTVERSION}_linux

MAINTAINER=	evgeniy@khramtsov.org
COMMENT=	Ultimate Oldschool PC Font Pack

LICENSE=	CC-BY-SA-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*Bm*/*.otb ${STAGEDIR}${FONTSDIR}
.for i in Ac Mx Px
	${INSTALL_DATA} ${WRKSRC}/*${i}*/*.ttf ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
