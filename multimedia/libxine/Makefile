# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	multimedia ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-lib/${PORTVERSION}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		vorbis:${PORTSDIR}/audio/libvorbis \
		speex:${PORTSDIR}/audio/speex \
		mng:${PORTSDIR}/graphics/libmng \
		png15:${PORTSDIR}/graphics/png \
		dvdread:${PORTSDIR}/multimedia/libdvdread \
		freetype:${PORTSDIR}/print/freetype2 \
		fame-0:${PORTSDIR}/multimedia/libfame \
		cdio:${PORTSDIR}/sysutils/libcdio \
		modplug:${PORTSDIR}/audio/libmodplug \
		vcdinfo:${PORTSDIR}/multimedia/vcdimager \
		theora:${PORTSDIR}/multimedia/libtheora \
		mad:${PORTSDIR}/audio/libmad \
		dca:${PORTSDIR}/multimedia/libdca \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		faad:${PORTSDIR}/audio/faad \
		vdpau:${PORTSDIR}/multimedia/libvdpau

BUILD_DEPENDS+=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat

.if !defined(PACKAGE_BUILDING)
LIB_DEPENDS+=	dvdcss.${DVDCSS_LIBVERSION}:${PORTSDIR}/multimedia/libdvdcss
.endif

USE_XZ=		yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack
USE_GMAKE=	yes
USE_XORG=	x11 xv xinerama
USE_GL=		gl glu
USE_PERL5_BUILD=yes
USE_SDL=	sdl
USE_LDCONFIG=	yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}" \
		EXTRA_X_LIBS="-lGL -lGLU -lXext -lX11 -lm"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ffmpeg
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-fno-force-addr -I${LOCALBASE}/include -I${LOCALBASE}/include/dvdread -I${LOCALBASE}/include/ffmeg
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32 \
		--enable-ipv6 \
		--with-external-libmad \
		--with-external-libdts \
		--with-libflac \
		--with-external-ffmpeg \
		--with-external-libfaad \
		--disable-v4l \
		--without-alsa \
		--disable-musepack \
		--enable-dvb
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	CACA ESOUND JACK GNOMEVFS2 PULSEAUDIO XVMC SMB AALIB \
		IMAGEMAGICK GTK2 WAVPACK VAAPI LIBBLURAY

MAN1=	xine-config.1 xine-list-1.2.1
MAN5=	xine.5

DOCSDIR=	${PREFIX}/share/doc/xine-lib
PLIST_SUB=	PLUGINSDIR="lib/xine/plugins/2.2"

# DVDCSS version hardcoded in src/input/input_dvd.c misc/cdda_server.c
# and src/input/libdvdnav/dvd_input.c (dlopen'ed)
DVDCSS_LIBVERSION=	3

PATCH_DIST_ARGS=	-d ${WRKSRC} -p1 --forward --quiet

.include <bsd.port.options.mk>

# Fix build WITH_DEBUG
.if defined(WITH_DEBUG)
DEBUG_FLAGS=	-g -O1
.endif

# Check for forced -O0 (or no -O)
.if ${CFLAGS:M-O0} == "-O0" || (${CFLAGS:M-O} == "" && \
	${CFLAGS:M-O[1-9a-z]*} == "")
IGNORE=		only builds with -O1 or higher, check CFLAGS
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MCACA}
LIB_DEPENDS+=	caca:${PORTSDIR}/graphics/libcaca
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
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
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
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	WITH_PULSEAUDIO=""
.else
PLIST_SUB+=	WITH_PULSEAUDIO="@comment "
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if ${PORT_OPTIONS:MXVMC}
.if defined(WITH_NVIDIA_GL) || exists(${LOCALBASE}/lib/libXvMCNVIDIA.so.1)
CONFIGURE_ARGS+=	--with-xvmc-lib=XvMCNVIDIA
LIB_DEPENDS+=	XvMCNVIDIA:${PORTSDIR}/x11/nvidia-driver
.else
CONFIGURE_ARGS+=	--with-xvmc-lib=XvMCW
LIB_DEPENDS+=	XvMC:${PORTSDIR}/x11/libXvMC
.endif
PLIST_SUB+=	WITH_XVMC=""
.else
CONFIGURE_ARGS+=	--disable-xvmc
PLIST_SUB+=	WITH_XVMC="@comment "
.endif

.if ${PORT_OPTIONS:MSMB}
LIB_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	WITH_SMB=""
CONFIGURE_ARGS+=	--enable-samba
.else
PLIST_SUB+=	WITH_SMB="@comment "
CONFIGURE_ARGS+=	--disable-samba
.endif

.if ${PORT_OPTIONS:MAALIB}
LIB_DEPENDS+=	aa:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	WITH_AALIB=""
.else
PLIST_SUB+=	WITH_AALIB="@comment "
CONFIGURE_ARGS+=	--disable-aalib --disable-aalibtest
.endif

.if ${PORT_OPTIONS:MMAGICK}
LIB_DEPENDS+=	MagickWand:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
CONFIGURE_ARGS+=	--without-imagemagick
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
PLIST_SUB+=	WITH_GTK2="@comment "
CONFIGURE_ARGS+=	--disable-gdkpixbuf
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WITH_WAVPACK=""
CONFIGURE_ARGS+=	--with-wavpack
.else
PLIST_SUB+=	WITH_WAVPACK="@comment "
CONFIGURE_ARGS+=	--without-wavpack
.endif

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	va:${PORTSDIR}/multimedia/libva
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
CONFIGURE_OPTS+=	--enable-bluray
LIB_DEPENDS+=	bluray:${PORTSDIR}/multimedia/libbluray
PLIST_SUB+=	LIBBLURAY=""
.else
CONFIGURE_OPTS+=	--disable-bluray
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

post-patch:
.if ${PORT_OPTIONS:MVAAPI}
	@${PATCH} ${PATCH_DIST_ARGS} <${FILESDIR}/ffmpeg-vaapi_xine-lib-1.2.2-defaultoff.diff
.endif
.for f in libtool ltmain.sh
	@${REINPLACE_CMD} -e \
		'/freebsd-elf)/,/;;/ s|major="\.$$current"|major=.`expr $$current - $$age`|; \
		/freebsd-elf)/,/;;/ s|versuffix="\.$$current"|versuffix="$$major"|' \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/src/input/input_dvd.c
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/misc/cdda_server.c
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/src/input/libdvdnav/dvd_input.c
	@${REINPLACE_CMD} -e "s|#define _ATOM QT_ATOM('', '', '', '')||" \
		${WRKSRC}/src/demuxers/demux_qt.c

pre-configure:
	@${REINPLACE_CMD} -e \
		's|THREAD_LIBS=".*"|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=".*"|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g ; \
		 s|-lgiconv|-liconv|g ; \
		 s|-funroll-loops||g ; \
		 s|LIBFFMPEG_CFLAGS|LIBFFMPEG_CPPFLAGS|g ; \
		 s|echo aout|echo elf|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		 's|-malign-loops|-falign-loops|g ; \
		  s|-malign-jumps|-falign-jumps|g ; \
		  s|-malign-functions|-falign-functions|g ; \
		  s|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
