PORTNAME=	lapackpp
DISTVERSION=	2022.05.00
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/icl/${PORTNAME}/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ API for the Linear Algebra PACKage

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lapacke>0:math/lapacke
LIB_DEPENDS=	libblaspp.so:math/blaspp \
		libopenblas.so:math/openblas
TEST_DEPENDS=	lapacke>0:math/lapacke
# fails to find xblas, see https://bitbucket.org/icl/lapackpp/issues/14/fails-to-find-xblas

USES=		cmake:testing fortran localbase:ldflags

CMAKE_OFF=	build_tests
CMAKE_TESTING_ON=	build_tests
CMAKE_TESTING_TARGET=	tester

post-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} test/tester

.include <bsd.port.mk>
