PORTNAME=	DoulosSIL
DISTVERSION=	6.200
CATEGORIES=	x11-fonts
MASTER_SITES=	https://software.sil.org/downloads/r/doulos/

MAINTAINER=	ports@zoltankiraly.com
COMMENT=	Doulos SIL TrueType font collection
WWW=		https://software.sil.org/doulos/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	${FONTSDIR}/${PORTNAME}-Regular.ttf

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt README.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
