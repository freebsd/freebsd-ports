PORTNAME=	siconos
DISTVERSION=	4.4.0.rc3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulation framework for nonsmooth dynamical systems

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
LIB_DEPENDS=	libcxsparse.so:math/suitesparse-cxsparse \
		libgmp.so:math/gmp \
		libldl.so:math/suitesparse-ldl \
		libopenblas.so:math/openblas

USES=		cmake compiler:c++17-lang fortran pkgconfig python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_OFF=	WITH_PYTHON_WRAPPER

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
