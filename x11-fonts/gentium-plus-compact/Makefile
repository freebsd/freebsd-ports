PORTNAME=	GentiumPlusCompact
DISTVERSION=	6.200
CATEGORIES=	x11-fonts
# Use the port maintainer's GitHub to fetch the font, since the SIL server
# embeds dynamic content into the file.
MASTER_SITES=	https://raw.githubusercontent.com/zoliky/distfiles/refs/heads/main/

MAINTAINER=	ports@zoltankiraly.com
COMMENT=	Gentium Plus TrueType font collection, compact variant
WWW=		https://software.sil.org/gentium/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	${FONTSDIR}/GentiumBookPlusCompact-Bold.ttf       \
		${FONTSDIR}/GentiumBookPlusCompact-BoldItalic.ttf \
		${FONTSDIR}/GentiumBookPlusCompact-Italic.ttf     \
		${FONTSDIR}/GentiumBookPlusCompact-Regular.ttf    \
		${FONTSDIR}/GentiumPlusCompact-Bold.ttf           \
		${FONTSDIR}/GentiumPlusCompact-BoldItalic.ttf     \
		${FONTSDIR}/GentiumPlusCompact-Italic.ttf         \
		${FONTSDIR}/GentiumPlusCompact-Regular.ttf

DOCSLIST=	FONTLOG.txt OFL-FAQ.txt README.txt         \
		documentation/pdf/resources.pdf            \
		documentation/pdf/features.pdf             \
		documentation/pdf/developer.pdf            \
		documentation/pdf/design.pdf               \
		documentation/pdf/faq.pdf                  \
		documentation/pdf/about.pdf                \
		documentation/pdf/history.pdf              \
		documentation/pdf/index.pdf                \
		documentation/pdf/charset.pdf              \
		documentation/pdf/support.pdf              \
		documentation/pdf/versions.pdf
PORTDOCS=	${DOCSLIST:C,^.*/,,}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
