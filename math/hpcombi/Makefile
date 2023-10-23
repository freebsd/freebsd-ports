PORTNAME=	HPCombi
PORTVERSION=	0.0.9
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

USES=		cmake:testing compiler:c++11-lang localbase:ldflags pkgconfig

NO_ARCH=	yes

#OPTIONS_DEFINE=	DOXYGEN TEST
OPTIONS_DEFINE=		DOXYGEN
OPTIONS_SUB=		yes
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_ON=	-DAPIDOC_DIR=${DOCSDIR}
TEST_CMAKE_ON=		-DBUILD_TESTING=1
TEST_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

.include <bsd.port.options.mk>

pre-configure-DOXYGEN-off:
	${REINPLACE_CMD} -e 's/add_subdirectory(doc)/# No doc/'	\
		${WRKSRC}/CMakeLists.txt

post-stage:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MV} ${STAGEDIR}${PREFIX}/.VERSION ${STAGEDIR}${DATADIR}/VERSION

post-stage-DOXYGEN-on:
	${MV} ${STAGEDIR}${PREFIX}/doc/${PORTNAME}/html ${STAGEDIR}${DOCSDIR}/
	${RM} -r ${STAGEDIR}${PREFIX}/doc

.include <bsd.port.mk>
