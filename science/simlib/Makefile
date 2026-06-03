PORTNAME=	simlib
DISTVERSION=	3.09
DISTVERSIONSUFFIX=	-20221108
CATEGORIES=	science
MASTER_SITES=	http://www.fit.vutbr.cz/~peringer/SIMLIB/source/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	SIMulation LIBrary for C++ programming language
WWW=		https://www.fit.vutbr.cz/~peringer/SIMLIB/index.html.en

LICENSE=	LGPL20

USES=		gmake
USE_LDCONFIG=	yes

ALL_TARGET=	all
TEST_TARGET=	test
CXXFLAGS+=	-Wno-inconsistent-missing-override

WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	doxygen

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_ALL_TARGET=	doc

do-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} doxygen ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsimlib.so

.include <bsd.port.mk>
