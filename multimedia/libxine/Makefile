# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	1.1.19
PORTREVISION=	7
CATEGORIES=	multimedia ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-lib/${PORTVERSION}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	makc

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		speex.1:${PORTSDIR}/audio/speex \
		mng.1:${PORTSDIR}/graphics/libmng \
		png.6:${PORTSDIR}/graphics/png \
		dvdread.4:${PORTSDIR}/multimedia/libdvdread \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fame-0.9.1:${PORTSDIR}/multimedia/libfame \
		cdio.12:${PORTSDIR}/sysutils/libcdio \
		modplug.1:${PORTSDIR}/audio/libmodplug \
		vcdinfo.2:${PORTSDIR}/multimedia/vcdimager \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		mad.2:${PORTSDIR}/audio/libmad \
		dca.0:${PORTSDIR}/multimedia/libdca \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		faad.2:${PORTSDIR}/audio/faad

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
		--without-alsa
MAKE_JOBS_SAFE=	yes

OPTIONS=	ARTS "Enable aRts support" off \
		CACA "Enable libcaca support" off \
		ESOUND "Enable EsounD support" off \
		JACK "Enable JACK support" off \
		GNOMEVFS2 "Enable GnomeVFS2 support" off \
		PULSEAUDIO "Enable PulseAudio support" off \
		XVMC "Enable XvMC support" off \
		SMB "Enable SMB protocol support" off \
		AALIB "Enable aalib support" off \
		IMAGEMAGICK "Enable ImageMagick support" off \
		GTK2 "Enable gdkpixbuf support" off \
		WAVPACK "Enable WavPack support" off \
		VAAPI "Enable VAAPI support" off \
		VDPAU "Enable VDPAU support" on

MAN1=	xine-config.1 xine-list-1.1.1
MAN5=	xine.5

DOCSDIR=	${PREFIX}/share/doc/xine-lib
PLIST_SUB=	PLUGINSDIR="lib/xine/plugins/1.29"

# DVDCSS version hardcoded in src/input/input_dvd.c misc/cdda_server.c
# and src/input/libdvdnav/dvd_input.c (dlopen'ed)
DVDCSS_LIBVERSION=	3

PATCH_DIST_ARGS=	-d ${WRKSRC} -p1 --forward --quiet

.include <bsd.port.options.mk>

# Fix build WITH_DEBUG
.if defined(WITH_DEBUG)
DEBUG_FLAGS=	-g -O1
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	WITH_ARTS=""
CONFIGURE_ARGS+=	--with-arts --enable-artstest
.else
PLIST_SUB+=	WITH_ARTS="@comment "
CONFIGURE_ARGS+=	--disable-arts --disable-artstest
.endif

.if defined(WITH_CACA)
LIB_DEPENDS+=	caca.0:${PORTSDIR}/graphics/libcaca
PLIST_SUB+=	WITH_CACA=""
.else
PLIST_SUB+=	WITH_CACA="@comment "
CONFIGURE_ARGS+=	--without-caca --disable-cacatest
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
PLIST_SUB+=	WITH_ESOUND=""
.else
PLIST_SUB+=	WITH_ESOUND="@comment "
CONFIGURE_ARGS+=	--without-esound
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
PLIST_SUB+=	WITH_JACK=""
.else
PLIST_SUB+=	WITH_JACK="@comment "
CONFIGURE_ARGS+=	--without-jack
.endif

.if defined(WITH_GNOMEVFS2)
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	WITH_GNOMEVFS2=""
.else
PLIST_SUB+=	WITH_GNOMEVFS2="@comment "
CONFIGURE_ARGS+=	--disable-gnomevfs
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	WITH_PULSEAUDIO=""
.else
PLIST_SUB+=	WITH_PULSEAUDIO="@comment "
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if defined(WITH_XVMC)
.if defined(WITH_NVIDIA_GL) || exists(${LOCALBASE}/lib/libXvMCNVIDIA.so.1)
CONFIGURE_ARGS+=	--with-xvmc-lib=XvMCNVIDIA
LIB_DEPENDS+=	XvMCNVIDIA.1:${PORTSDIR}/x11/nvidia-driver
.else
CONFIGURE_ARGS+=	--with-xvmc-lib=XvMCW
LIB_DEPENDS+=	XvMC.1:${PORTSDIR}/x11/libXvMC
.endif
PLIST_SUB+=	WITH_XVMC=""
.else
CONFIGURE_ARGS+=	--disable-xvmc
PLIST_SUB+=	WITH_XVMC="@comment "
.endif

.if defined(WITH_SMB)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	WITH_SMB=""
.else
PLIST_SUB+=	WITH_SMB="@comment "
CONFIGURE_ARGS+=	--disable-samba
.endif

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	WITH_AALIB=""
.else
PLIST_SUB+=	WITH_AALIB="@comment "
CONFIGURE_ARGS+=	--disable-aalib --disable-aalibtest
.endif

.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	MagickWand.5:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
CONFIGURE_ARGS+=	--without-imagemagick
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
PLIST_SUB+=	WITH_GTK2="@comment "
CONFIGURE_ARGS+=	--disable-gdkpixbuf
.endif

.if defined(WITH_WAVPACK)
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
PLIST_SUB+=	WITH_WAVPACK=""
CONFIGURE_ARGS+=	--with-wavpack
.else
PLIST_SUB+=	WITH_WAVPACK="@comment "
CONFIGURE_ARGS+=	--without-wavpack
.endif

.if defined(WITH_VAAPI)
LIB_DEPENDS+=	va.1:${PORTSDIR}/multimedia/libva
.endif

.if defined(WITH_VDPAU)
PATCHFILES+=	xine-vdpau.bz2
USE_AUTOTOOLS=	autoconf
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/multimedia/libvdpau
PLIST_SUB+=	VDPAU=""
.else
PLIST_SUB+=	VDPAU="@comment "
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
.if defined(WITH_VAAPI)
	${PATCH} ${PATCH_DIST_ARGS} <${FILESDIR}/ffmpeg-vaapi_xine-lib-1.1.19-initerrorhack.diff
.endif
.if defined(WITH_VDPAU)
	for i in `${LS} ${FILESDIR}/extrapatch-vdpau*`; do \
		${PATCH} ${PATCH_DIST_ARGS} <$$i ;\
	done
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
		  s|-malign-functions|-falign-functions|g' ${WRKSRC}/configure

pre-build:
	@${CP} -p ${LOCALBASE}/include/dts.h ${WRKSRC}/src/libdts/

.include <bsd.port.mk>
