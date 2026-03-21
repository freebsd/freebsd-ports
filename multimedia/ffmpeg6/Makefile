PORTNAME=	ffmpeg
PORTVERSION=	6.1.4
CATEGORIES=	multimedia audio net
MASTER_SITES=	https://ffmpeg.org/releases/
PKGNAMESUFFIX=	6

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server (legacy 6.* series)
WWW=		https://ffmpeg.org/

LICENSE=		GPLv3+ LGPL3+
LICENSE_COMB=		multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_aarch64=	as:devel/binutils
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_armv6=	as:devel/binutils
BUILD_DEPENDS_armv7=	as:devel/binutils
BUILD_DEPENDS_i386=	nasm:devel/nasm

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa			\
		--disable-libopencore-amrnb	\
		--disable-libopencore-amrwb	\
		--disable-libaribb24		\
		--disable-libbs2b		\
		--disable-libcaca		\
		--disable-libcdio		\
		--disable-libcodec2		\
		--disable-libdavs2		\
		--disable-libdc1394		\
		--disable-libfdk-aac		\
		--disable-libflite		\
		--disable-libfribidi		\
		--disable-libglslang		\
		--disable-libgme		\
		--disable-libgsm		\
		--disable-libilbc		\
		--disable-libjack		\
		--disable-libkvazaar		\
		--disable-ladspa		\
		--disable-libklvanc		\
		--disable-liblensfun		\
		--disable-libbluray		\
		--disable-librsvg		\
		--disable-lv2			\
		--disable-libmfx		\
		--disable-libmodplug		\
		--disable-libmysofa		\
		--disable-nvenc			\
		--disable-openal		\
		--disable-opencl		\
		--disable-opengl		\
		--disable-libopenh264		\
		--disable-libopenjpeg		\
		--disable-libopenmpt		\
		--disable-libopenvino		\
		--disable-pocketsphinx		\
		--disable-libpulse		\
		--disable-librabbitmq		\
		--disable-librav1e		\
		--disable-librist		\
		--disable-librubberband		\
		--disable-sdl2			\
		--disable-libsmbclient		\
		--disable-libsnappy		\
		--disable-sndio			\
		--disable-libsoxr		\
		--disable-libspeex		\
		--disable-libsrt		\
		--disable-libssh		\
		--disable-libtensorflow		\
		--disable-libtesseract		\
		--disable-libtheora		\
		--disable-libtwolame		\
		--disable-libuavs3d		\
		--disable-vapoursynth		\
		--disable-libvidstab		\
		--disable-libvo-amrwbenc	\
		--disable-vulkan		\
		--disable-libxavs2		\
		--disable-libxvid		\
		--disable-outdev=xv		\
		--disable-libzimg		\
		--disable-libzmq		\
		--disable-libzvbi		\
		--disable-gcrypt		\
		--disable-mbedtls		\
		--disable-openssl		\
		--disable-libtls		\
		--disable-nonfree
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-stripping
.else
CONFIGURE_ARGS+=--disable-debug
.endif
CONFIGURE_LOG=	ffbuild/config.log
USES=		compiler:c11 cpe gmake localbase:ldflags perl5 \
		pkgconfig shebangfix tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
SHEBANG_FILES=	doc/texi2pod.pl
NOPRECIOUSMAKEVARS=	yes # ARCH

.ifdef PKGNAMESUFFIX
PORTSCOUT=	limit:^6\.
PREFIX=		${LOCALBASE}/${PKGBASE} # avoid conflict with the default
.endif

OPTIONS_DEFINE=	DOCS

# aom
LIB_DEPENDS+=		libaom.so:multimedia/aom
CONFIGURE_ARGS+=	--enable-libaom

# asm support
CONFIGURE_ARGS+=	--enable-asm

# ass
LIB_DEPENDS+=		libass.so:multimedia/libass
CONFIGURE_ARGS+=	--enable-libass

# dav1d
LIB_DEPENDS+=		libdav1d.so:multimedia/dav1d
CONFIGURE_ARGS+=	--enable-libdav1d

# docs
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html
DOCS_CONFIGURE_ENABLE=	htmlpages
DOCS_BINARY_ALIAS=	makeinfo=${FALSE} # force texi2html

# drm
LIB_DEPENDS+=		libdrm.so:graphics/libdrm
CONFIGURE_ARGS+=	--enable-libdrm

# fontconfig
LIB_DEPENDS+=		libfontconfig.so:x11-fonts/fontconfig
CONFIGURE_ARGS+=	--enable-fontconfig

# freetype
LIB_DEPENDS+=		libfreetype.so:print/freetype2
CONFIGURE_ARGS+=	--enable-libfreetype

# frei0r
BUILD_DEPENDS+=		${LOCALBASE}/include/frei0r.h:graphics/frei0r
CONFIGURE_ARGS+=	--enable-frei0r

# gnutls
LIB_DEPENDS+=		libgnutls.so:security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls

# gmp
LIB_DEPENDS+=		libgmp.so:math/gmp
CONFIGURE_ARGS+=	--enable-gmp

# iconv
USES+=			iconv
CONFIGURE_ARGS+=	--enable-iconv

# lame
LIB_DEPENDS+=		libmp3lame.so:audio/lame
CONFIGURE_ARGS+=	--enable-libmp3lame

# libxml
USES+=			gnome
USE_GNOME+=		libxml2
CONFIGURE_ARGS+=	--enable-libxml2

# libv4l
BUILD_DEPENDS+=		v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS+=		libv4l2.so:multimedia/libv4l
CONFIGURE_ARGS+=	--enable-libv4l2

# network
CONFIGURE_ARGS+=	--enable-network

# optimizations
CONFIGURE_ARGS+=	--enable-optimizations

# opus
LIB_DEPENDS+=		libopus.so:audio/opus
CONFIGURE_ARGS+=	--enable-libopus

# rtcpu
CONFIGURE_ARGS+=	--enable-runtime-cpudetect

# svt-av1
LIB_DEPENDS+=		libSvtAv1Enc.so:multimedia/svt-av1
CONFIGURE_ARGS+=	--enable-libsvtav1

# vaapi
LIB_DEPENDS+=		libva.so:multimedia/libva
CONFIGURE_ARGS+=	--enable-vaapi

# vdpau
USES+=			xorg
USE_XORG+=		x11
LIB_DEPENDS+=		libvdpau.so:multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau

# vmaf
LIB_DEPENDS+=		libvmaf.so:multimedia/vmaf
CONFIGURE_ARGS+=	--enable-libvmaf

# vorbis
LIB_DEPENDS+=		libvorbisenc.so:audio/libvorbis
CONFIGURE_ARGS+=	--enable-libvorbis

# vp8
LIB_DEPENDS+=		libvpx.so:multimedia/libvpx
CONFIGURE_ARGS+=	--enable-libvpx

# webp
LIB_DEPENDS+=		libwebp.so:graphics/webp
CONFIGURE_ARGS+=	--enable-libwebp

# x264
LIB_DEPENDS+=		libx264.so:multimedia/libx264
CONFIGURE_ARGS+=	--enable-libx264

# x265
LIB_DEPENDS+=		libx265.so:multimedia/x265
CONFIGURE_ARGS+=	--enable-libx265

# xcb
#USES+=			xorg
USE_XORG+=		xcb
CONFIGURE_ARGS+=	--enable-libxcb

# License knobs
CONFIGURE_ARGS+=	--enable-version3

INSTALL_TARGET=	install-progs install-doc install-data \
		install-libs install-headers install-examples
#TEST_TARGET=	check

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
MAKE_ENV+=	V=1
LDFLAGS_aarch64=-Wl,-z,notext
LDFLAGS_armv6=	-Wl,-z,notext
LDFLAGS_armv7=	-Wl,-z,notext
LDFLAGS_i386=	-Wl,-z,notext

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/share/man" \
		--datadir="${DATADIR}" \
		--docdir="${DOCSDIR}" \
		--pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--disable-static \
		--disable-libcelt \
		--enable-shared \
		--enable-pic \
		--enable-gpl \
		--cc="${CC}" \
		--cxx="${CXX}"

DOC_FILES=	Changelog CREDITS INSTALL.md LICENSE.md MAINTAINERS \
		README.md RELEASE_NOTES
# under doc subdirectory
DOC_DOCFILES=	APIchanges *.txt
PORTDOCS=	*

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${DOC_FILES}" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${DOC_DOCFILES}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
