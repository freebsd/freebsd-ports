PORTNAME=	jellyfin-ffmpeg7
PORTVERSION=	7.1.4.3
CATEGORIES=	multimedia

MAINTAINER=	michaeljohnson@ahze.net
COMMENT=	FFmpeg with patches for HDR tone mapping (tonemapx/libplacebo)
WWW=		https://github.com/jellyfin/jellyfin-ffmpeg

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	nasm:devel/nasm \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
PATCH_DEPENDS=	quilt:devel/quilt
LIB_DEPENDS=	libass.so:multimedia/libass \
		libbluray.so:multimedia/libbluray \
		libchromaprint.so:audio/chromaprint \
		libdav1d.so:multimedia/dav1d \
		libfdk-aac.so:audio/fdk-aac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgmp.so:math/gmp \
		libharfbuzz.so:print/harfbuzz \
		libmp3lame.so:audio/lame \
		libopenmpt.so:audio/libopenmpt \
		libopus.so:audio/opus \
		libplacebo.so:graphics/libplacebo \
		libshaderc_shared.so:graphics/shaderc \
		libSvtAv1Enc.so:multimedia/svt-av1 \
		libtheoraenc.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx \
		libvulkan.so:graphics/vulkan-loader \
		libwebp.so:graphics/webp \
		libx264.so:multimedia/libx264 \
		libx265.so:multimedia/x265 \
		libzimg.so:graphics/sekrit-twc-zimg \
		libzvbi.so:devel/libzvbi \
		libgnutls.so:security/gnutls \
		libxml2.so:textproc/libxml2 \
		libiconv.so:converters/libiconv \
		libva.so:multimedia/libva \
		libva-drm.so:multimedia/libva \
		libdrm.so:graphics/libdrm \
		libvdpau.so:multimedia/libvdpau \
		libX11.so:x11/libX11 \
		libasound.so:audio/alsa-lib \
		libsndio.so:audio/sndio

USES=		compiler:c17 gmake localbase:ldflags pkgconfig tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	jellyfin
GH_PROJECT=	jellyfin-ffmpeg
GH_TAGNAME=	v${PORTVERSION:C/\.([0-9]+)$/-\1/}

# Everything installs into a private subdir so nothing collides with
# multimedia/ffmpeg or with jellyfin-ffmpeg8. Standard PREFIX is untouched:
#   ${PREFIX}/lib/jellyfin-ffmpeg7/bin/ffmpeg   <- real binary
#   ${PREFIX}/lib/jellyfin-ffmpeg7/lib/libav*   <- bundled libs (ldconfig)
#   ${PREFIX}/bin/jellyfin-ffmpeg7              <- version-suffixed symlink
# The only files outside the private dir are the suffixed bin/ symlinks.
# --enable-rpath (below) makes the binary load these bundled libs even when
# base multimedia/ffmpeg is installed with the same soname.
# The bundled headers stay under the private prefix so they do not collide
# with multimedia/ffmpeg's include/libav*. The pkg-config files are relocated
# in post-install to libdata/pkgconfig with a jellyfin-ffmpeg7- filename prefix
# (Requires tokens rewritten to match) so they are discoverable system-wide
# without colliding with multimedia/ffmpeg's libav*.pc.
JFFMPEG_DIR=	${PREFIX}/lib/jellyfin-ffmpeg7
USE_LDCONFIG=	${JFFMPEG_DIR}/lib

post-patch:
	cd ${WRKSRC} && QUILT_PATCHES=debian/patches quilt push -a || \
	    QUILT_PATCHES=debian/patches quilt applied | ${GREP} -q 0094

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	ffbuild/config.log
NOPRECIOUSMAKEVARS=	yes

MAKE_ENV+=	V=1

CONFIGURE_ARGS=	--prefix="${JFFMPEG_DIR}" \
		--libdir="${JFFMPEG_DIR}/lib" \
		--enable-rpath \
		--target-os=freebsd \
		--cc="${CC}" --cxx="${CXX}" \
		--extra-version=Jellyfin \
		--disable-doc \
		--disable-ffplay \
		--disable-static \
		--disable-libxcb \
		--disable-sdl2 \
		--disable-xlib \
		--enable-lto=auto \
		--enable-gpl \
		--enable-version3 \
		--enable-shared \
		--enable-gmp \
		--enable-gnutls \
		--enable-libxml2 \
		--enable-libass \
		--enable-libfreetype \
		--enable-libfribidi \
		--enable-libfontconfig \
		--enable-libharfbuzz \
		--enable-libbluray \
		--enable-chromaprint \
		--enable-libdrm \
		--enable-libfdk-aac \
		--enable-libmp3lame \
		--enable-libopenmpt \
		--enable-libopus \
		--enable-libtheora \
		--enable-libvorbis \
		--enable-libdav1d \
		--enable-libsvtav1 \
		--enable-libwebp \
		--enable-libvpx \
		--enable-libx264 \
		--enable-libx265 \
		--enable-libzimg \
		--enable-libzvbi \
		--enable-libplacebo \
		--enable-libshaderc \
		--enable-vulkan \
		--enable-vaapi \
		--enable-vdpau \
		--disable-ffnvcodec

INSTALL_TARGET=	install-progs install-data install-libs install-headers

post-install:
	# Version-suffixed symlinks in /usr/local/bin for PATH access
	${LN} -sf ../lib/jellyfin-ffmpeg7/bin/ffmpeg ${STAGEDIR}${PREFIX}/bin/jellyfin-ffmpeg7
	${LN} -sf ../lib/jellyfin-ffmpeg7/bin/ffprobe ${STAGEDIR}${PREFIX}/bin/jellyfin-ffprobe7
	# Unversioned alias: this port is the current jellyfin-ffmpeg. Consumers
	# (jellyfin, immich) reference the stable /usr/local/bin/jellyfin-ffmpeg.
	${LN} -sf ../lib/jellyfin-ffmpeg7/bin/ffmpeg ${STAGEDIR}${PREFIX}/bin/jellyfin-ffmpeg
	${LN} -sf ../lib/jellyfin-ffmpeg7/bin/ffprobe ${STAGEDIR}${PREFIX}/bin/jellyfin-ffprobe
	# Relocate the private pkg-config files to libdata/pkgconfig under a
	# jellyfin-ffmpeg7- prefix. Rewrite Name and the Requires cross-refs so
	# pkg-config resolves them to each other, not to multimedia/ffmpeg.
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	@cd ${STAGEDIR}${JFFMPEG_DIR}/lib/pkgconfig && for pc in *.pc; do \
		${SED} -E \
			-e 's/^(Name: )/\1jellyfin-ffmpeg7-/' \
			-e '/^Requires/ s/lib(avcodec|avdevice|avfilter|avformat|avutil|postproc|swresample|swscale)/jellyfin-ffmpeg7-lib\1/g' \
			$${pc} > ${STAGEDIR}${PREFIX}/libdata/pkgconfig/jellyfin-ffmpeg7-$${pc}; \
	done
	${RM} -r ${STAGEDIR}${JFFMPEG_DIR}/lib/pkgconfig

.include <bsd.port.mk>
