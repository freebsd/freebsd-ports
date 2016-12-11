# Created by: alex
# $FreeBSD$

PORTNAME=	xine
PORTVERSION=	1.2.6
PORTREVISION=	8
CATEGORIES=	multimedia ipv6
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
		libvdpau.so:multimedia/libvdpau
.if !defined(PACKAGE_BUILDING)
# DVDCSS version hardcoded in src/input/input_dvd.c misc/cdda_server.c
# and src/input/libdvdnav/dvd_input.c (dlopen'ed)
LIB_DEPENDS+=	libdvdcss.so.2:multimedia/libdvdcss
.endif

USES=		compiler cpe execinfo gmake iconv libtool:keepla \
		localbase pathfix perl5 pkgconfig tar:xz
CPE_PRODUCT=	xine-lib
CPE_VENDOR=	xine
GNU_CONFIGURE=	yes
USE_XORG=	x11 xv xinerama xext sm ice
USE_GL=		gl glu
USE_PERL5=	build
USE_SDL=	sdl
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32 \
		--enable-ipv6 \
		--with-external-libmad \
		--with-external-libdts \
		--with-libflac \
		--with-external-ffmpeg \
		--with-external-libfaad \
		--disable-real-codecs \
		--disable-v4l \
		--without-alsa \
		--disable-musepack \
		--enable-dvb
MAKE_ENV=	V=1

DOCSDIR=	${PREFIX}/share/doc/xine-lib
# Please sync with XINE_PLUGINSDIR in multimedia/xine
# and multimedia/vdr-plugin-xineliboutput
PLUGINSDIR=	lib/xine/plugins/2.5
PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

BROKEN_aarch64=		Fails to configure: error: no acceptable as found in $PATH

OPTIONS_DEFINE=	NLS CACA ESOUND JACK GNOMEVFS2 PULSEAUDIO XVMC SMB AALIB \
		IMAGEMAGICK PIXBUF WAVPACK VAAPI LIBBLURAY
OPTIONS_DEFAULT=VAAPI
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_CONFIGURE_OFF=	--without-caca --disable-cacatest
ESOUND_USE=		GNOME=esound
ESOUND_CONFIGURE_OFF=	--without-esound
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--without-jack
GNOMEVFS2_USE=		GNOME=gnomevfs2
GNOMEVFS2_CONFIGURE_OFF=--disable-gnomevfs
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=--without-pulseaudio
.if defined(WITH_NVIDIA304_GL) || exists(${LOCALBASE}/lib/libXvMCNVIDIA.so.1)
XVMC_CONFIGURE_ON=	--with-xvmc-lib=XvMCNVIDIA
XVMC_LIB_DEPENDS=	libXvMCNVIDIA.so:x11/nvidia-driver-304
.else
XVMC_CONFIGURE_ON=	--with-xvmc-lib=XvMCW
XVMC_LIB_DEPENDS=	libXvMC.so:x11/libXvMC
.endif
XVMC_CONFIGURE_OFF=	--disable-xvmc
SMB_LIB_DEPENDS=	libsmbclient.so:net/samba-libsmbclient
SMB_CONFIGURE_ENV=	LIBSMBCLIENT_LIBS="-L${LOCALBASE}/lib -lsmbclient" \
			LIBSMBCLIENT_CFLAGS="-I${LOCALBASE}/include"
SMB_CONFIGURE_ENABLE=	samba
AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_CONFIGURE_OFF=	--disable-aalib --disable-aalibtest
IMAGEMAGICK_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick
IMAGEMAGICK_CONFIGURE_OFF=	--without-imagemagick
PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_CONFIGURE_OFF=	--disable-gdkpixbuf
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_WITH=	wavpack
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CONFIGURE_ON=	--enable-vaapi
LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	bluray

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-fomit-frame-pointer
.endif

.if ${CONFIGURE_ARGS:M*--without-imagemagick*} == "" || ${CONFIGURE_ARGS:M*-disable-gdkpixbuf*} == ""
PLIST_SUB+=	WITH_DMX_IMAGE=""
.else
PLIST_SUB+=	WITH_DMX_IMAGE="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	WITH_VIDIX=""
.else
PLIST_SUB+=	WITH_VIDIX="@comment "
CONFIGURE_ARGS+=	--disable-vidix
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} -e 's|-fno-rename-registers||' \
		${WRKSRC}/src/libw32dll/wine/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/src/video_out/Makefile.in
	@${REINPLACE_CMD} -e "s|#define _ATOM QT_ATOM('', '', '', '')||" \
		${WRKSRC}/src/demuxers/demux_qt.c
	@${REINPLACE_CMD} -e \
		's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' \
		${WRKSRC}/configure

# XXX older nvidia-driver versions don't support opengl 2.0 so this
# plugin might not get built:
post-install:
	@if ! [ -e "${STAGEDIR}${PREFIX}/${PLUGINSDIR}/xineplug_vo_out_opengl2.so" ]; then \
		${REINPLACE_CMD} -e '/xineplug_vo_out_opengl2.so/d' \
			${TMPPLIST}; \
	fi
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PLUGINSDIR}/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PLUGINSDIR}/post/*.so

.include <bsd.port.post.mk>
