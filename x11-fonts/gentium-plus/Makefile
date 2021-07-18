# Created by: Matthew Seaman

PORTNAME=	GentiumPlus
PORTVERSION=	6.001
CATEGORIES=	x11-fonts
MASTER_SITES=	http://software.sil.org/downloads/r/gentium/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Plus TrueType font collection

LICENSE=	OFL11

NO_ARCH=	yes
NO_BUILD=	yes

USES=		fonts zip

PLIST_FILES=	${FONTSDIR}/GentiumBookPlus-Bold.ttf       \
		${FONTSDIR}/GentiumBookPlus-BoldItalic.ttf \
		${FONTSDIR}/GentiumBookPlus-Italic.ttf     \
		${FONTSDIR}/GentiumBookPlus-Regular.ttf    \
		${FONTSDIR}/GentiumPlus-Bold.ttf           \
		${FONTSDIR}/GentiumPlus-BoldItalic.ttf     \
		${FONTSDIR}/GentiumPlus-Italic.ttf         \
		${FONTSDIR}/GentiumPlus-Regular.ttf

SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt \
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
