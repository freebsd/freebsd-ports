PORTNAME=	mlpack
DISTVERSION=	4.5.1
CATEGORIES=	math # machine-learning
MASTER_SITES=	https://mlpack.org/files/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, flexible machine learning library
WWW=		https://www.mlpack.org/ \
		https://github.com/mlpack/mlpack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_FreeBSD_13=	compilation fails with clang-19, see https://github.com/mlpack/mlpack/issues/3825
BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/mlpack/mlpack/issues/3825
BROKEN_i386=	undefined symbol: __atomic_load

HPP_DEPENDS=	armadillo>0:math/armadillo \
		cereal>0:devel/cereal \
		ensmallen>0:math/ensmallen \
		${LOCALBASE}/include/stb/stb_image.h:devel/stb
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake:testing compiler:c++14-lang pkgconfig

CMAKE_ARGS=	-DSTB_IMAGE_INCLUDE_DIR=${LOCALBASE}/include/stb
CMAKE_OFF=	BUILD_PYTHON_BINDINGS BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		EXECUTABLES
OPTIONS_DEFAULT=	EXECUTABLES
OPTIONS_SUB=		yes

EXECUTABLES_DESC=	Build command-line executables
EXECUTABLES_CMAKE_BOOL=	BUILD_CLI_EXECUTABLES
EXECUTABLES_VARS_OFF=	NO_ARCH=yes

.include <bsd.port.mk>
