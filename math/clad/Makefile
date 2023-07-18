PORTNAME=	clad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic differentiation for C/C++
WWW=		https://github.com/vgvassilev/clad

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake compiler:c++14-lang llvm:15,build,run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	vgvassilev

CMAKE_ARGS=	-DClang_DIR=${LLVM_PREFIX}/lib/cmake/clang \
		-DLLVM_DIR=${LLVM_PREFIX}/lib/cmake/llvm
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
