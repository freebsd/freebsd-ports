PORTNAME=	Gentium
PORTVERSION=	7.000
CATEGORIES=	x11-fonts
MASTER_SITES=	http://software.sil.org/downloads/r/gentium/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium TrueType font collection
WWW=		https://software.sil.org/gentium/

LICENSE=	OFL11

NO_ARCH=	yes
NO_BUILD=	yes

USES=		fonts zip

PLIST_FILES=	${FONTSDIR}/Gentium-Bold.ttf            \
		${FONTSDIR}/Gentium-BoldItalic.ttf      \
		${FONTSDIR}/Gentium-ExtraBold.ttf       \
		${FONTSDIR}/Gentium-ExtraBoldItalic.ttf \
		${FONTSDIR}/Gentium-Italic.ttf          \
		${FONTSDIR}/Gentium-Medium.ttf          \
		${FONTSDIR}/Gentium-MediumItalic.ttf    \
		${FONTSDIR}/Gentium-Regular.ttf         \
		${FONTSDIR}/Gentium-SemiBold.ttf        \
		${FONTSDIR}/Gentium-SemiBoldItalic.ttf

SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt \
		documentation/pdf/about.pdf     \
		documentation/pdf/charset.pdf   \
		documentation/pdf/design.pdf    \
		documentation/pdf/developer.pdf \
		documentation/pdf/faq.pdf       \
		documentation/pdf/features.pdf  \
		documentation/pdf/greek.pdf     \
		documentation/pdf/history.pdf   \
		documentation/pdf/index.pdf     \
		documentation/pdf/resources.pdf \
		documentation/pdf/support.pdf   \
		documentation/pdf/v7changes.pdf \
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
