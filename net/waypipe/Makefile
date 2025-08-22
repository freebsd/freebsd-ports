PORTNAME=	waypipe
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.4
PORTREVISION=	2
CATEGORIES=	net wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Network transparency with Wayland
WWW=		https://gitlab.freedesktop.org/mstoeckl/waypipe

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.GPLv3

USES=		cargo meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mstoeckl
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	FFMPEG LZ4 MANPAGES VULKAN ZSTD
OPTIONS_DEFAULT=FFMPEG LZ4 MANPAGES VULKAN ZSTD

FFMPEG_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
			glslc:graphics/shaderc \
			ffmpeg>0:multimedia/ffmpeg
FFMPEG_MESON_ENABLED=	with_video

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_MESON_ENABLED=	with_lz4

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

VULKAN_BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli \
			vulkan-loader>0:graphics/vulkan-loader
VULKAN_USES=		gl
VULKAN_USE=		GL=gbm
VULKAN_MESON_ENABLED=	with_dmabuf with_gbm

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	with_zstd

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo test/,/^[[:space:]]*)/s/-v/&', '&/" \
		${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e '/cargo/s/-v/& &/' \
		${WRKSRC}/compile_wrapper.sh

.include <bsd.port.mk>
