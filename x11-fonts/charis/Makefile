# Created by: bf <bf@FreeBSD.org>

PORTNAME=	CharisSIL
PORTVERSION=	6.000
CATEGORIES=	x11-fonts
MASTER_SITES=	https://software.sil.org/downloads/r/charis/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Charis SIL TrueType font collection

LICENSE=	OFL11

USES=		fonts zip

MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes
NO_ARCH=	yes

.for type in Bold BoldItalic Italic Regular
PLIST_FILES+=	${FONTSDIR}/${PORTNAME}-${type}.ttf
.endfor

OPTIONS_DEFINE=	DOCS

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
