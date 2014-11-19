# Created by: alex
# $FreeBSD$

PORTNAME=	xine
PORTVERSION=	1.2.6
CATEGORIES=	multimedia ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-lib/${PORTVERSION}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		liba52.so:${PORTSDIR}/audio/liba52 \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libspeex.so:${PORTSDIR}/audio/speex \
		libmng.so:${PORTSDIR}/graphics/libmng \
		libpng15.so:${PORTSDIR}/graphics/png \
		libdvdread.so:${PORTSDIR}/multimedia/libdvdread \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfame.so:${PORTSDIR}/multimedia/libfame \
		libcdio_paranoia.so:${PORTSDIR}/sysutils/libcdio-paranoia \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libvcdinfo.so:${PORTSDIR}/multimedia/vcdimager \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libmad.so:${PORTSDIR}/audio/libmad \
		libdca.so:${PORTSDIR}/multimedia/libdca \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libfaad.so:${PORTSDIR}/audio/faad \
		libvdpau.so:${PORTSDIR}/multimedia/libvdpau
.if !defined(PACKAGE_BUILDING)
# DVDCSS version hardcoded in src/input/input_dvd.c misc/cdda_server.c
# and src/input/libdvdnav/dvd_input.c (dlopen'ed)
LIB_DEPENDS+=	libdvdcss.so.2:${PORTSDIR}/multimedia/libdvdcss
.endif

USES=		compiler gmake iconv libtool:keepla pathfix perl5 pkgconfig \
		execinfo tar:xz
GNU_CONFIGURE=	yes
USE_XORG=	x11 xv xinerama xext sm ice
USE_GL=		gl glu
USE_PERL5=	build
USE_SDL=	sdl
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
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

OPTIONS_DEFINE=	CACA ESOUND JACK GNOMEVFS2 PULSEAUDIO XVMC SMB AALIB \
		IMAGEMAGICK PIXBUF WAVPACK VAAPI LIBBLURAY

DOCSDIR=	${PREFIX}/share/doc/xine-lib
# Please sync with XINE_PLUGINSDIR in multimedia/xine
# and multimedia/vdr-plugin-xineliboutput
PLUGINSDIR=	lib/xine/plugins/2.5
PLIST_SUB=	PLUGINSDIR="${PLUGINSDIR}"

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-fomit-frame-pointer
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MCACA}
LIB_DEPENDS+=	libcaca.so:${PORTSDIR}/graphics/libcaca
PLIST_SUB+=	WITH_CACA=""
.else
PLIST_SUB+=	WITH_CACA="@comment "
CONFIGURE_ARGS+=	--without-caca --disable-cacatest
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
PLIST_SUB+=	WITH_ESOUND=""
.else
PLIST_SUB+=	WITH_ESOUND="@comment "
CONFIGURE_ARGS+=	--without-esound
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
PLIST_SUB+=	WITH_JACK=""
.else
PLIST_SUB+=	WITH_JACK="@comment "
CONFIGURE_ARGS+=	--without-jack
.endif

.if ${PORT_OPTIONS:MGNOMEVFS2}
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	WITH_GNOMEVFS2=""
.else
PLIST_SUB+=	WITH_GNOMEVFS2="@comment "
CONFIGURE_ARGS+=	--disable-gnomevfs
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	WITH_PULSEAUDIO=""
.else
PLIST_SUB+=	WITH_PULSEAUDIO="@comment "
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if ${PORT_OPTIONS:MXVMC}
.if defined(WITH_NVIDIA304_GL) || exists(${LOCALBASE}/lib/libXvMCNVIDIA.so.1)
CONFIGURE_ARGS+=	--with-xvmc-lib=XvMCNVIDIA
LIB_DEPENDS+=	libXvMCNVIDIA.so:${PORTSDIR}/x11/nvidia-driver-304
.else
CONFIGURE_ARGS+=	--with-xvmc-lib=XvMCW
LIB_DEPENDS+=	libXvMC.so:${PORTSDIR}/x11/libXvMC
.endif
PLIST_SUB+=	WITH_XVMC=""
.else
CONFIGURE_ARGS+=	--disable-xvmc
PLIST_SUB+=	WITH_XVMC="@comment "
.endif

.if ${PORT_OPTIONS:MSMB}
LIB_DEPENDS+=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	WITH_SMB=""
CONFIGURE_ENV+=	LIBSMBCLIENT_LIBS="-L${LOCALBASE}/lib -lsmbclient" \
		LIBSMBCLIENT_CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--enable-samba
.else
PLIST_SUB+=	WITH_SMB="@comment "
CONFIGURE_ARGS+=	--disable-samba
.endif

.if ${PORT_OPTIONS:MAALIB}
LIB_DEPENDS+=	libaa.so:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	WITH_AALIB=""
.else
PLIST_SUB+=	WITH_AALIB="@comment "
CONFIGURE_ARGS+=	--disable-aalib --disable-aalibtest
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
CONFIGURE_ARGS+=	--without-imagemagick
.endif

.if ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
PLIST_SUB+=	WITH_GTK2=""
.else
PLIST_SUB+=	WITH_GTK2="@comment "
CONFIGURE_ARGS+=	--disable-gdkpixbuf
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	libwavpack.so:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WITH_WAVPACK=""
CONFIGURE_ARGS+=	--with-wavpack
.else
PLIST_SUB+=	WITH_WAVPACK="@comment "
CONFIGURE_ARGS+=	--without-wavpack
.endif

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	libva.so:${PORTSDIR}/multimedia/libva
PLIST_SUB+=	VAAPI=""
CONFIGURE_ARGS+=	--enable-vaapi
.else
PLIST_SUB+=	VAAPI="@comment "
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
CONFIGURE_ARGS+=	--enable-bluray
LIB_DEPENDS+=	libbluray.so:${PORTSDIR}/multimedia/libbluray
PLIST_SUB+=	LIBBLURAY=""
.else
CONFIGURE_ARGS+=	--disable-bluray
PLIST_SUB+=	LIBBLURAY="@comment "
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
.if ${PORT_OPTIONS:MVAAPI}
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/src/video_out/Makefile.in
.endif
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

.include <bsd.port.post.mk>
