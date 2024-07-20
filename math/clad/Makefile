PORTNAME=	clad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic differentiation for C/C++
WWW=		https://github.com/vgvassilev/clad

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/License.txt

TEST_DEPENDS=	kokkos>0:devel/kokkos

USES=		cmake:testing llvm:16,build,run localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	vgvassilev

CMAKE_ARGS=	-DClang_DIR=${LLVM_PREFIX}/lib/cmake/clang \
		-DLLVM_DIR=${LLVM_PREFIX}/lib/cmake/llvm \
		-DLLVM_EXTERNAL_LIT=${LLVM_PREFIX}/bin/llvm-lit
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	FREEBSD_BUILD_TESTS FREEBSD_BUILD_DEMOS
CMAKE_TESTING_TARGET=	check-clad

#CXXFLAGS+=	-D_OPENMP

post-patch:
	@${REINPLACE_CMD} \
		-e ' \
			s|import lit|&${LLVM_VERSION}|; \
			s|lit\.|lit${LLVM_VERSION}.| \
		' \
		${WRKSRC}/test/lit.cfg

# tests fail to compile: https://github.com/vgvassilev/clad/issues/993

.include <bsd.port.mk>
