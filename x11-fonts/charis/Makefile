PORTNAME=	Charis
PORTVERSION=	7.000
CATEGORIES=	x11-fonts
MASTER_SITES=	https://software.sil.org/downloads/r/charis/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Charis SIL TrueType font collection
WWW=		https://software.sil.org/charis/

LICENSE=	OFL11

USES=		fonts zip

MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes
NO_ARCH=	yes

.for type in Bold BoldItalic Italic Medium MediumItalic Regular SemiBold \
	SemiBoldItalic
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
