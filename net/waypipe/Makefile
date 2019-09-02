# $FreeBSD$

PORTNAME=	waypipe
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	net

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Network transparency with Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols \
		wayland>=1.15:graphics/wayland

USES=		compiler:c11 localbase:ldflags meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mstoeckl
GL_COMMIT=	f78ad85b04ef95daa9a1671aa0375d0e77d19b2f
PLIST_FILES=	bin/${PORTNAME}

# XXX Drop after FreeBSD 12.0 EOL
.if exists(/usr/lib/clang/6.0.0) || exists(/usr/lib/clang/6.0.1)
.if ${CC} == cc && (${MACHINE_ARCH} == amd64 || ${MACHINE_ARCH} == i386)
USES:=		${USES:Ncompiler*} # silence warning
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
.endif
.endif

OPTIONS_DEFINE=	FFMPEG LZ4 MANPAGES OPENGL VAAPI ZSTD
OPTIONS_DEFAULT=FFMPEG LZ4 MANPAGES OPENGL VAAPI ZSTD

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_MESON_ENABLED=	with_video

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_MESON_ENABLED=	with_lz4

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

OPENGL_USES=		gl
OPENGL_USE=		GL=gbm
OPENGL_LIB_DEPENDS=	libdrm.so:graphics/libdrm
OPENGL_MESON_ENABLED=	with_dmabuf

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_MESON_ENABLED=	with_vaapi
VAAPI_IMPLIES=		FFMPEG

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	with_zstd

.include <bsd.port.mk>
