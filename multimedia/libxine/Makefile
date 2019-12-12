# Created by: alex
# $FreeBSD$

PORTNAME=	xine
PORTVERSION=	1.2.9
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-lib/${PORTVERSION}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:multimedia/v4l_compat
LIB_DEPENDS=	libFLAC.so:audio/flac \
		liba52.so:audio/liba52 \
		libvorbis.so:audio/libvorbis \
		libspeex.so:audio/speex \
		libmng.so:graphics/libmng \
		libpng.so:graphics/png \
		libdvdread.so:multimedia/libdvdread \
		libfreetype.so:print/freetype2 \
		libfame.so:multimedia/libfame \
		libcdio_paranoia.so:sysutils/libcdio-paranoia \
		libmodplug.so:audio/libmodplug \
		libvcdinfo.so:multimedia/vcdimager \
		libtheora.so:multimedia/libtheora \
		libmad.so:audio/libmad \
		libdca.so:multimedia/libdca \
		libavcodec.so:multimedia/ffmpeg \
		libfaad.so:audio/faad \
		libvdpau.so:multimedia/libvdpau \
		libvpx.so:multimedia/libvpx \
		libiso9660.so:sysutils/libcdio \
		libogg.so:audio/libogg \
		libdvdnav.so:multimedia/libdvdnav

USES=		compiler cpe gl gmake gnome iconv libtool:keepla jpeg \
		localbase pathfix perl5 pkgconfig sdl tar:xz xorg
LLD_UNSAFE=	yes
CPE_PRODUCT=	xine-lib
CPE_VENDOR=	xine
GNU_CONFIGURE=	yes
USE_XORG=	x11 xcb xv xinerama xext sm ice
USE_GL=		gl glu
USE_PERL5=	build
USE_SDL=	sdl
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-libflac \
		--disable-real-codecs \
		--disable-v4l \
		--without-alsa \
		--without-esound \
		--disable-musepack

MAKE_ENV=	V=1
MAKE_ARGS=	pkgdatadir="${DATADIR}" \
		datadir="${DATADIR}" \
		libdir="${PREFIX}/lib"

CFLAGS_i386=			-fomit-frame-pointer

DOCSDIR=	${PREFIX}/share/doc/xine-lib
# Please sync with XINE_PLUGINSDIR in multimedia/xine
# and multimedia/vdr-plugin-xineliboutput
PLUGINSDIR=	lib/xine/plugins/2.7
PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

OPTIONS_DEFINE=		DOCS NLS CACA DVB DMX_IMAGE IPV6 IMAGEMAGICK JACK \
			GNOMEVFS2 PIXBUF PULSEAUDIO XVMC SMB SNDIO AALIB WAVPACK \
			VAAPI LIBBLURAY
OPTIONS_DEFAULT=	DVB PIXBUF VAAPI
OPTIONS_DEFINE_i386=	W32DLL
OPTIONS_DEFAULT_i386=	W32DLL
OPTIONS_SUB=		yes

DMX_IMAGE_DESC=		DMX image plugin
DVB_DESC=		DVB plugin
W32DLL_DESC=		Win32 codec support

AALIB_LIB_DEPENDS=		libaa.so:graphics/aalib
AALIB_CONFIGURE_ENABLE=		aalib
CACA_LIB_DEPENDS=		libcaca.so:graphics/libcaca
CACA_CONFIGURE_WITH=		caca
DVB_CONFIGURE_ENABLE=		dvb
GNOMEVFS2_USE=			GNOME=glib20,gconf2,gnomevfs2
GNOMEVFS2_CONFIGURE_ENABLE=	gnomevfs
IMAGEMAGICK_CONFIGURE_WITH=	imagemagick
IMAGEMAGICK_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick6
IMAGEMAGICK_IMPLIES=		DMX_IMAGE
IPV6_CONFIGURE_ENABLE=		ipv6
JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_WITH=		jack
LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	bluray
NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls
PIXBUF_CONFIGURE_ENABLE=	gdkpixbuf
PIXBUF_IMPLIES=			DMX_IMAGE
PIXBUF_USE=			GNOME=gdkpixbuf2,glib20
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
SMB_USES=			samba:lib
SMB_CONFIGURE_ENV=		LIBSMBCLIENT_LIBS="-L${SAMBALIBS} -lsmbclient" \
				LIBSMBCLIENT_CFLAGS="-I${SAMBAINCLUDES}"
SMB_CONFIGURE_ENABLE=		samba
SNDIO_CONFIGURE_ENABLE=		sndio
SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio
VAAPI_LIB_DEPENDS=		libva.so:multimedia/libva \
				libva-glx.so:multimedia/libva-glx
VAAPI_CONFIGURE_ENABLE=		vaapi
W32DLL_CONFIGURE_ENABLE=	w32dll
W32DLL_PLIST_FILES=		${PLUGINSDIR}/xineplug_decode_qt.so \
				${PLUGINSDIR}/xineplug_decode_w32dll.so
WAVPACK_LIB_DEPENDS=		libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_WITH=		wavpack

.if defined(WITH_NVIDIA304_GL) || exists(${LOCALBASE}/lib/libXvMCNVIDIA.so.1)
XVMC_CONFIGURE_WITH=		xvmc-lib=XvMCNVIDIA
XVMC_LIB_DEPENDS=		libXvMCNVIDIA.so:x11/nvidia-driver-304
.else
XVMC_CONFIGURE_WITH=		xvmc-lib=XvMCW
XVMC_LIB_DEPENDS=		libXvMC.so:x11/libXvMC
.endif
XVMC_CONFIGURE_ENABLE=		xvmc

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} -e 's|-fno-rename-registers||' \
		${WRKSRC}/src/libw32dll/wine/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/src/video_out/Makefile.in
	@${REINPLACE_CMD} -e "s|#define _ATOM QT_ATOM('', '', '', '')||" \
		${WRKSRC}/src/demuxers/demux_qt.c \
		${WRKSRC}/configure
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PLUGINSDIR}/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PLUGINSDIR}/post/*.so

.include <bsd.port.post.mk>
