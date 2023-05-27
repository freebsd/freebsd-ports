PORTNAME=	osqp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Operator Splitting Quadratic Program solver for optimization problems
WWW=		https://osqp.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing # 4 tests fail, see https://github.com/osqp/osqp/issues/532
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	oxfordcontrol
GH_TUPLE=	oxfordcontrol:qdldl:7ab0fca:q/lin_sys/direct/qdldl/qdldl_sources

CMAKE_OFF=	BUILD_STATIC_LIBS BUILD_EXAMPLES UNITTESTS
CMAKE_TESTING_ON=	UNITTESTS

.include <bsd.port.mk>
