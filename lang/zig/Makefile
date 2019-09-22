# $FreeBSD$

PORTNAME=	zig
DISTVERSION=	0.4.0
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Language designed for robustness, optimality, and maintainability

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

_LLVM_VER=	80
BUILD_DEPENDS=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}

USES=		cmake compiler:c++11-lang tar:xz

OPTIONS_DEFINE=		STATIC
OPTIONS_DEFAULT=	STATIC

STATIC_RUN_DEPENDS_OFF=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}
STATIC_CMAKE_BOOL=	CMAKE_SKIP_INSTALL_RPATH \
			ZIG_STATIC

.include <bsd.port.mk>
