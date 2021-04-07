PORTNAME=	osqp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Operator Splitting Quadratic Program solver for optimization problems

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	oxfordcontrol
GH_TUPLE=	oxfordcontrol:qdldl:7ab0fca:q/lin_sys/direct/qdldl/qdldl_sources
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_STATIC_LIBS BUILD_EXAMPLES UNITTESTS

.include <bsd.port.mk>
