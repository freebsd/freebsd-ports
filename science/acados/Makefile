PORTNAME=	acados
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and embedded solvers for nonlinear optimal control
WWW=		https://github.com/acados/acados

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblasfeo.so:math/blasfeo \
		libhpipm.so:math/hpipm
		# math/casadi should be a dependency, but somehow cmake doesn't look for it

USES=		cmake:testing localbase:ldflags
USE_GITHUB=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		OSQP
OPTIONS_DEFAULT=	OSQP

OSQP_DESC=		Build with OSQP solver
OSQP_CMAKE_BOOL=	ACADOS_WITH_OSQP
OSQP_LIB_DEPENDS=	libosqp.so:math/osqp

QPOASES_DESC=		Build with QPOASES solver
QPOASES_CMAKE_BOOL=	ACADOS_WITH_QPOASES
QPOASES_LIB_DEPENDS=	libqpOASES.so:math/qposases
QPOASES_BROKEN=		error: unknown type name 'namespace'

post-patch: # workaround for https://github.com/acados/acados/issues/1413
	@${FIND} ${WRKSRC} -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | \
		${XARGS} ${REINPLACE_CMD} -E 's,"osqp/include/,"osqp/,'
	@${FIND} ${WRKSRC} -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | \
		${XARGS} ${REINPLACE_CMD} \
			-E '\
				s,"(blasfeo|catch|daqp|hpmpc|hpipm)/include/,",; \
				s|qpOASES_e|qpOASES|; \
				s|qpOASES/QProblem.h|qpOASES/QProblem.hpp| \
			'

.include <bsd.port.mk>
