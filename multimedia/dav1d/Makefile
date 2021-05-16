PORTNAME=	dav1d
DISTVERSION=	0.9.0
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small and fast AV1 decoder

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		compiler:c11 meson
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	videolan
GL_COMMIT=	8636b4f2bb79ec7c2f711218ff6bcdd02a2f3f1a
LDFLAGS_i386=	-Wl,-z,notext

OPTIONS_DEFINE=	SDL TEST
OPTIONS_SUB=	yes

SDL_USES=	pkgconfig sdl
SDL_USE=	SDL=sdl2
SDL_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
SDL_LIB_DEPENDS=	libplacebo.so:graphics/libplacebo \
			libvulkan.so:graphics/vulkan-loader
SDL_MESON_TRUE=	enable_examples

TEST_GL_TUPLE=	videolan:dav1d-test-data:4fd8f87d7df509fda1af51e5e2f7c415692afaef:testdata/tests/dav1d-test-data
TEST_MESON_TRUE=enable_tests testdata_tests

.if make(makesum) # for optional distfiles
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}"
.endif

# https://bugs.llvm.org/show_bug.cgi?id=40635
.if !empty(CFLAGS:M-flto*)
MESON_ARGS+=	${MESON_ARGS_${CHOSEN_COMPILER_TYPE}_${ARCH}}
MESON_ARGS_clang_amd64=	-Dstack_alignment=16
MESON_ARGS_clang_i386=	-Dstack_alignment=4
.endif

pre-install-TEST-on: do-test

.include <bsd.port.mk>
