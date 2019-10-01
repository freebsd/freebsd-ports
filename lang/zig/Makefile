# $FreeBSD$

PORTNAME=	zig
DISTVERSION=	0.5.0
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Language designed for robustness, optimality, and maintainability

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=		static_assert failed "static_assert(sizeof(ZigClangAPValue) == sizeof(clang::APValue), "")"
IGNORE_FreeBSD_11=	expects getrandom(2) which is unavailable on FreeBSD < 12.0

_LLVM_VER=	90
BUILD_DEPENDS=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}

USES=		cmake compiler:c++11-lang tar:xz

OPTIONS_DEFINE=		STATIC
OPTIONS_DEFAULT=	STATIC

STATIC_RUN_DEPENDS_OFF=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}
STATIC_CMAKE_BOOL=	CMAKE_SKIP_INSTALL_RPATH \
			ZIG_STATIC

.include <bsd.port.mk>
