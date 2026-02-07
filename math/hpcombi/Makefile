PORTNAME=	HPCombi
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	math devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Fast combinatorics in C++ using SSE/AVX instruction sets
WWW=		https://github.com/hivert/HPCombi

LICENSE=	GPLv3

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	uses AVX instruction set

BUILD_DEPENDS=	sparsehash>0:devel/sparsehash
LIB_DEPENDS=	libbenchmark.so:devel/benchmark
TEST_DEPENDS=	boost-libs>0:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	hivert

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pathfix	\
		pkgconfig

CMAKE_ARGS=	-DHPCOMBI_DISABLE_MARCH_NATIVE:BOOL=on

NO_ARCH=	yes

#OPTIONS_DEFINE=	DOXYGEN TEST
OPTIONS_DEFINE=		DOXYGEN
OPTIONS_SUB=		yes
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_ON=	-DAPIDOC_DIR=${DOCSDIR}
TEST_CMAKE_ON=		-DBUILD_TESTING=1
TEST_LIB_DEPENDS=	libCatch2.so:devel/catch2

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}

.include <bsd.port.options.mk>

pre-configure-DOXYGEN-off:
	${REINPLACE_CMD} -e 's/add_subdirectory(doc)/# No doc/'	\
		${WRKSRC}/CMakeLists.txt

post-stage-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${BUILD_WRKSRC}/doc/html &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
