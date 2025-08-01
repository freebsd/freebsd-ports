PORTNAME=	siconos
DISTVERSION=	4.5.0
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulation framework for nonsmooth dynamical systems
WWW=		https://nonsmooth.gricad-pages.univ-grenoble-alpes.fr/siconos/index.html

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=		non-constant-expression cannot be narrowed from type 'unsigned int' to 'npy_intp', see https://github.com/siconos/siconos/issues/416

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		help2man:misc/help2man
LIB_DEPENDS=	libBulletCollision.so:devel/bullet \
		libcxsparse.so:math/suitesparse-cxsparse \
		libgmp.so:math/gmp \
		libldl.so:math/suitesparse-ldl \
		libopenblas.so:math/openblas
TEST_DEPENDS=	cppunit>0:devel/cppunit

USES=		cmake:testing compiler:c++17-lang fortran pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_ON=	CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT SICONOS_SYSTEM_WIDE_INSTALL
CMAKE_OFF=	WITH_GIT WITH_TESTING
CMAKE_TESTING_ON=	WITH_TESTING # tests are broken, see https://github.com/siconos/siconos/issues/415

CFLAGS+=	-DCLOCKTIME -DCLOCKS_PER_SEC=128 # workaround for 'Undefined symbol "ftime"', see https://github.com/siconos/siconos/issues/411

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	#PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	WITH_PYTHON_WRAPPER
PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_PY_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
PYTHON_BUILD_DEPENDS=	${PYTHON_PY_DEPENDS} \
			swig:devel/swig
PYTHON_RUN_DEPENDS=	${PYTHON_PY_DEPENDS}
PYTHON_BROKEN=		compilation fails, see https://github.com/siconos/siconos/issues/501

.include <bsd.port.mk>
