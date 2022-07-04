PORTNAME=	blaspp
DISTVERSION=	2022.05.00
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/icl/blaspp/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ API for the Basic Linear Algebra Subroutines

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas
TEST_DEPENDS=	cblas>0:math/cblas

USES=		cmake:testing fortran localbase # fails to find openblas w/out USES=fortran for some reason, needs investigation

CMAKE_OFF=	build_tests
CMAKE_TESTING_ON=	build_tests # tests fail to run, see https://bitbucket.org/icl/blaspp/issues/19/tests-arent-run-with-tester-target-when
CMAKE_TESTING_TARGET=	tester

.include <bsd.port.mk>
