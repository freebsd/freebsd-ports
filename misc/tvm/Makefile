PORTNAME=	tvm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning compiler stack for cpu, gpu and specialized accelerators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dmlc-core>0:devel/dmlc-core \
		rang>0:devel/rang
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang localbase
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	apache
GH_PROJECT=	tvm
GH_TUPLE=	dmlc:dlpack:ddeb264:dlpack/3rdparty/dlpack

CMAKE_ON=	INSTALL_DEV # Install compiler infrastructure (as opposed to runtime-only)
CMAKE_ARGS=	-DDMLC_PATH=${LOCALBASE}/include -DRANG_PATH=${LOCALBASE}/include
CMAKE_TESTING_TARGET=	cpptest

LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		LLVM
OPTIONS_DEFAULT=	LLVM

LLVM_VERSION=		${LLVM_DEFAULT}
LLVM_DESC=		With LLVM support for model compilation
LLVM_CMAKE_ON=		-DUSE_LLVM=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}
LLVM_BUILD_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
LLVM_RUN_DEPENDS=	llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
CMAKE_ARGS+=	-DUSE_RPC:BOOL=OFF
.endif

post-test:
	@cd ${TEST_WRKSRC} && ./cpptest

.include <bsd.port.mk>
