# $FreeBSD$

PORTNAME=	tvm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep learning compiler stack for cpu, gpu and specialized accelerators

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dmlc-core>0:devel/dmlc-core \
		rang>0:devel/rang

USES=		cmake compiler:c++11-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	incubator-tvm
GH_TUPLE=	dmlc:dlpack:0acb731:dlpack/3rdparty/dlpack \
		dmlc:dmlc-core:808f485:dmlc_core/3rdparty/dmlc-core
USE_LDCONFIG=	yes

LDFLAGS+=	/usr/lib/libexecinfo.so

OPTIONS_DEFINE=		LLVM COMPILER
OPTIONS_DEFAULT=	LLVM COMPILER
OPTIONS_SUB=		yes

LLVM_DESC=		With LLVM support for model compillation
LLVM_CMAKE_ON=		-DUSE_LLVM=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}
LLVM_BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LLVM_RUN_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

COMPILER_DESC=		Install compiler infrastructure (as opposed to runtime-only)
COMPILER_CMAKE_BOOL=	INSTALL_DEV

post-install-COMPILER-on: # delete headers that conflict with dmlc-core: https://github.com/apache/incubator-tvm/issues/4530
	@${RM} -r ${STAGEDIR}${PREFIX}/include/dmlc

.include <bsd.port.mk>
