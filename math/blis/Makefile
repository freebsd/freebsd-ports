# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blis
PORTVERSION=	0.7.0
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Software framework for high-performance BLAS-like libraries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

OPTIONS_DEFINE=	PARA CBLAS
PARA_DESC=	use pthread parallelization
CBLAS_DESC=	build the CBLAS compatibility layer
OPTIONS_DEFAULT=	PARA CBLAS
OPTIONS_SUB=		yes

USE_GITHUB=	yes
GH_ACCOUNT=	flame

USES=		compiler gmake python shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	build/flatten-headers.py

HAS_CONFIGURE=	yes

.include <bsd.port.options.mk>

# enable BLAS and static/shared libs by default
CONFIGURE_ARGS+=	--enable-blas \
			--prefix=${PREFIX} \
			--enable-shared \
			--enable-static
#--prefix=PREFIX

.if ${PORT_OPTIONS:MPARA}
CONFIGURE_ARGS+=	-t pthreads
.endif

.if ${PORT_OPTIONS:MCBLAS}
CONFIGURE_ARGS+=	--enable-cblas
.endif

.if ${ARCH} == amd64
LIBNAME=	x86_64
CONFIGURE_ARGS+=	x86_64
PLIST_SUB+=	ARCH="x86_64"
.else
LIBNAME=	generic
CONFIGURE_ARGS+=	generic
PLIST_SUB+=	ARCH="generic"
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.else
LLVM_VER=	90
BUILD_DEPENDS+=	llvm${LLVM_VER}>=0:devel/llvm${LLVM_VER}
CC=	${LOCALBASE}/bin/clang${LLVM_VER}
CXX=	${LOCALBASE}/bin/clang++${LLVM_VER}
.endif

.include <bsd.port.post.mk>
