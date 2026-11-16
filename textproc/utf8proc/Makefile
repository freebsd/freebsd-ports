PORTNAME=	utf8proc
DISTVERSION=	2.12.0
CATEGORIES=	textproc devel
MASTER_SITES=	https://github.com/JuliaStrings/utf8proc/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Clean C library for processing UTF-8 Unicode data
WWW=		https://juliastrings.github.io/utf8proc/ \
		https://github.com/JuliaStrings/utf8proc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	UCD>=0:textproc/UCD

USES=		cmake:testing

CMAKE_OFF=	LIB_FUZZING_ENGINE \
		UTF8PROC_ENABLE_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	UTF8PROC_ENABLE_TESTING
USE_LDCONFIG=	yes

PORTDOCS=	NEWS.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

pre-test:
	${MKDIR} ${TEST_WRKSRC}/data
	${LN} -fs ${LOCALBASE}/share/unicode/ucd/NormalizationTest.txt ${TEST_WRKSRC}/data/NormalizationTest.txt
	${LN} -fs ${LOCALBASE}/share/unicode/ucd/auxiliary/GraphemeBreakTest.txt ${TEST_WRKSRC}/data/GraphemeBreakTest.txt

.include <bsd.port.mk>
