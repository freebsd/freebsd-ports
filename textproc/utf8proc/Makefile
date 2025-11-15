PORTNAME=	utf8proc
DISTVERSION=	2.11.1
CATEGORIES=	textproc devel
MASTER_SITES=	https://github.com/JuliaStrings/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://www.unicode.org/Public/17.0.0/ucd/:testfiles1 \
		https://www.unicode.org/Public/17.0.0/ucd/auxiliary/:testfiles2
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		NormalizationTest.txt:testfiles1 \
		GraphemeBreakTest.txt:testfiles2
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	UTF-8 processing library
WWW=		https://juliastrings.github.io/utf8proc/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake:testing pathfix
USE_LDCONFIG=	yes

PORTDOCS=	NEWS.md README.md

CMAKE_TESTING_ON=	UTF8PROC_ENABLE_TESTING

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

pre-test:
	${MKDIR} ${BUILD_WRKSRC}/data
	${CP} ${DISTDIR}/${DIST_SUBDIR}/*.txt ${BUILD_WRKSRC}/data

.include <bsd.port.mk>
