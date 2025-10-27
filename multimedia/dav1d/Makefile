PORTNAME=	dav1d
DISTVERSION=	1.5.2
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small and fast AV1 decoder
WWW=		https://code.videolan.org/videolan/dav1d

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
LDFLAGS_i386=	-Wl,-z,notext

OPTIONS_DEFINE=	SDL TEST XXHASH
OPTIONS_SUB=	yes

SDL_USES=	pkgconfig sdl
SDL_USE=	SDL=sdl2
SDL_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
SDL_LIB_DEPENDS=	libplacebo.so:graphics/libplacebo \
			libvulkan.so:graphics/vulkan-loader
SDL_MESON_TRUE=	enable_examples

TEST_GL_TUPLE=	videolan:dav1d-test-data:${DISTVERSION}:testdata/tests/dav1d-test-data
TEST_MESON_TRUE=enable_tests testdata_tests

XXHASH_DESC=	xxHash 3 muxer
XXHASH_BUILD_DEPENDS=	xxhash>0:devel/xxhash
XXHASH_USES=		localbase
XXHASH_MESON_ENABLED=	xxhash_muxer

.if make(makesum) # for optional distfiles
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}"
.endif

# https://github.com/llvm/llvm-project/issues/39981
.if !empty(CFLAGS:M-flto*)
MESON_ARGS+=	${MESON_ARGS_${CHOSEN_COMPILER_TYPE}_${ARCH}}
MESON_ARGS_clang_amd64=	-Dstack_alignment=16
MESON_ARGS_clang_i386=	-Dstack_alignment=4
.endif

post-build-TEST-on:
# Ensure checkasm is built before tests are run
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} meson-test-prereq

pre-install-TEST-on: do-test

.include <bsd.port.mk>
