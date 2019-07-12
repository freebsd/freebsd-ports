# $FreeBSD$

PORTNAME=	waypipe
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	net

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/commit/
PATCHFILES+=	04b9a483e346.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Network transparency with Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols \
		wayland>=1.15:graphics/wayland

USES=		compiler:c11 meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mstoeckl
GL_COMMIT=	8cf7845e63470490af3af95e178ba5fa74d8056b
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	FFMPEG LZ4 MANPAGES OPENGL ZSTD
OPTIONS_DEFAULT=FFMPEG LZ4 MANPAGES OPENGL ZSTD

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

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	with_zstd

.include <bsd.port.mk>
