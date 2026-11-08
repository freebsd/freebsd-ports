PORTNAME=	acados
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and embedded solvers for nonlinear optimal control
WWW=		https://github.com/acados/acados

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# math/casadi should be a dependency, but somehow cmake doesn't look for it
LIB_DEPENDS=	libblasfeo.so:math/blasfeo \
		libhpipm.so:math/hpipm
TEST_DEPENDS=	catch>0:devel/catch \
		math/eigen3>0:math/eigen3

USES=		cmake:testing localbase:ldflags
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	ACADOS_UNIT_TESTS

OPTIONS_DEFINE=		OSQP

OSQP_DESC=		Build with OSQP solver
OSQP_CMAKE_BOOL=	ACADOS_WITH_OSQP
OSQP_LIB_DEPENDS=	libosqp.so:math/osqp
OSQP_BROKEN=		Not compatible with math/osqp 1.0.0, see https://github.com/acados/acados/issues/1413

post-patch: # adapt bundled-dependency include paths to system blasfeo/hpipm
	@${FIND} ${WRKSRC} -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) | \
		${XARGS} ${REINPLACE_CMD} -E 's,"osqp/include/,"osqp/, '
	@${FIND} ${WRKSRC} -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) | \
		${XARGS} ${REINPLACE_CMD} \
			-E '\
				s,"(blasfeo|catch|daqp|hpmpc|hpipm)/include/,",; \
				s|qpOASES_e|qpOASES|; \
				s|qpOASES/QProblem.h|qpOASES/QProblem.hpp| \
			'

# tests as of 0.6.0: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
