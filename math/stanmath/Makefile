PORTNAME=	stanmath
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ template library for automatic differentiation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LOCALBASE}/include/boost/math/constants/constants.hpp:devel/boost-libs \
		${LOCALBASE}/include/tbb/task_arena.h:devel/onetbb # compiler define -DTBB_INTERFACE_NEW chooses oneTBB as opposed to TBB
TEST_DEPENDS=	gmake:devel/gmake

USES=		eigen:3,run python:test shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	stan-dev
GH_PROJECT=	math

SHEBANG_FILES=	runTests.py

MAKE_ENV=	TBB_LIB="${LOCALBASE}/lib"

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} stan ${STAGEDIR}${PREFIX}/include

do-test: # fails to compile: https://github.com/stan-dev/math/issues/2571
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./runTests.py test/unit test/prob

.include <bsd.port.mk>
