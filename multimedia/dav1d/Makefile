# $FreeBSD$

PORTNAME=	dav1d
DISTVERSION=	0.4.0
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
GL_COMMIT=	5f63e531b9d10a09afe0a6b4875ca4852a7e58c1

OPTIONS_DEFINE=	SDL TEST
OPTIONS_SUB=	yes

SDL_USES=	pkgconfig sdl
SDL_USE=	SDL=sdl2
SDL_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers
SDL_LIB_DEPENDS=	libplacebo.so:graphics/libplacebo \
			libvulkan.so:graphics/vulkan-loader

TEST_GL_TUPLE=	videolan:dav1d-test-data:3ccdd3df4fb8583d58bcc0101e315b00ec3ae130:testdata/tests/dav1d-test-data
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

post-patch-SDL-off:
	${REINPLACE_CMD} 's/sdl2/&-disabled/2' ${WRKSRC}/tools/meson.build

pre-install-TEST-on: do-test

.include <bsd.port.mk>
