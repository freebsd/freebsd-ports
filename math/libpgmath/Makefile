# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpgmath
DISTVERSION=	g20180904
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Compiler-callable math intrinsics library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64
IGNORE_FreeBSD_11=	not supported on older than 12.0, no cpuid bit support

BUILD_DEPENDS=	llvm60>=0:devel/llvm60
RUN_DEPENDS=	llvm60>=0:devel/llvm60

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flang-compiler
GH_PROJECT=	flang
GH_TAGNAME=	53e368b

CMAKE_ARGS+=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config60 \
		-DCMAKE_CXX_COMPILER=${LOCALBASE}/llvm60/bin/clang++ \
		-DCMAKE_C_COMPILER=${LOCALBASE}/llvm60/bin/clang

WRKSRC_SUBDIR=	runtime/libpgmath

PLIST_FILES=	lib/libpgmath.a \
		lib/libpgmath.so

.include <bsd.port.mk>
