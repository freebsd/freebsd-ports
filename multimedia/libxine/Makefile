# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	1.1.4
PORTREVISION=	3
CATEGORIES=	multimedia ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

BUILD_DEPENDS=	${LOCALBASE}/lib/libdts.a:${PORTSDIR}/multimedia/libdts
LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		speex.1:${PORTSDIR}/audio/speex \
		mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		dvdread.5:${PORTSDIR}/multimedia/libdvdread \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fame-0.9.1:${PORTSDIR}/multimedia/libfame \
		cdio.7:${PORTSDIR}/sysutils/libcdio \
		modplug.0:${PORTSDIR}/audio/libmodplug \
		vcdinfo.2:${PORTSDIR}/multimedia/vcdimager \
		theora.2:${PORTSDIR}/multimedia/libtheora \
		mad.2:${PORTSDIR}/audio/libmad

USE_GCC=	3.4+
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fno-force-addr -I${LOCALBASE}/include -I${LOCALBASE}/include/dvdread -I${X11BASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}" \
		EXTRA_X_LIBS="-lGL -lGLU -lXext -lX11 -lm"
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32 --enable-ipv6 \
		--mandir=${PREFIX}/man --with-external-libmad \
		--with-external-libdts --with-libflac --disable-v4l

MAN1=	xine-config.1
MAN5=	xine.5

DOCSDIR=	${TARGETDIR}/share/doc/xine-lib

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ARTS) && (exists(${LOCALBASE}/bin/artsc-config) || defined(WITH_ARTS))
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	WITH_ARTS=""
.else
PLIST_SUB+=	WITH_ARTS="@comment "
CONFIGURE_ARGS+=	--disable-arts --disable-artstest
.endif

.if !defined(WITHOUT_CACA) && (exists(${LOCALBASE}/lib/libcaca.a) || defined(WITH_CACA))
BUILD_DEPENDS+=	caca-config:${PORTSDIR}/graphics/libcaca
PLIST_SUB+=	WITH_CACA=""
.else
PLIST_SUB+=	WITH_CACA="@comment "
CONFIGURE_ARGS+=	--disable-caca --disable-cacatest
.endif

.if !defined(WITHOUT_ESOUND) && (${HAVE_GNOME:Mesound} != "" || defined(WITH_ESOUND))
USE_GNOME+=	esound
PLIST_SUB+=	WITH_ESOUND=""
.else
PLIST_SUB+=	WITH_ESOUND="@comment "
CONFIGURE_ARGS+=	--without-esound
.endif

.if !defined(WITHOUT_JACK) && (exists(${LOCALBASE}/lib/libjack.so) || defined(WITH_JACK))
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
PLIST_SUB+=	WITH_JACK=""
.else
PLIST_SUB+=	WITH_JACK="@comment "
CONFIGURE_ARGS+=	--disable-jack
.endif

.if !defined(WITHOUT_GNOMEVFS2) && (${HAVE_GNOME:Mgnomevfs2} != "" || defined(WITH_GNOMEVFS2))
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	WITH_GNOMEVFS2=""
.else
PLIST_SUB+=	WITH_GNOMEVFS2="@comment "
CONFIGURE_ARGS+=	--disable-gnomevfs
.endif

.if !defined(WITHOUT_PULSEAUDIO) && (exists(${LOCALBASE}/lib/libpulse.so.0) || defined(WITH_PULSEAUDIO))
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	WITH_PULSEAUDIO=""
.else
PLIST_SUB+=	WITH_PULSEAUDIO="@comment "
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if !defined(WITHOUT_XVMC) && (exists(${X11BASE}/lib/libXvMCNVIDIA.so.1) || defined(WITH_XVMC))
CONFIGURE_ARGS+=--with-xvmc-lib=XvMCNVIDIA
LIB_DEPENDS+=	XvMCNVIDIA.1:${PORTSDIR}/x11/nvidia-driver
PLIST_SUB+=	WITH_XVMC=""
.else
PLIST_SUB+=	WITH_XVMC="@comment "
.endif

.if !defined(WITHOUT_SMB) && (exists(${LOCALBASE}/lib/libsmbclient.so.0) || defined (WITH_SMB))
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	WITH_SMB=""
.else
PLIST_SUB+=	WITH_SMB="@comment "
CONFIGURE_ARGS+=	--disable-samba
.endif

.if !defined(WITHOUT_AALIB) && (exists(${LOCALBASE}/lib/libaa.so.1) || defined (WITH_AALIB))
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	WITH_AALIB=""
.else
PLIST_SUB+=	WITH_AALIB="@comment "
CONFIGURE_ARGS+=	--disable-aalib --disable-aalibtest
.endif

.if !defined(WITHOUT_IMAGEMAGICK) && (exists(${LOCALBASE}/lib/libWand.so.10) || defined (WITH_IMAGEMAGICK))
LIB_DEPENDS+=	Wand.10:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
CONFIGURE_ARGS+=	--disable-imagemagick
.endif

.if !defined(WITHOUT_GTK2) && (${HAVE_GNOME:Mgtk20} != "" || defined(WITH_GTK2))
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
PLIST_SUB+=	WITH_GTK2="@comment "
CONFIGURE_ARGS+=	--disable-gdkpixbuf
.endif

.if ${CONFIGURE_ARGS:M*--disable-imagemagick*} == "" || ${CONFIGURE_ARGS:M*-disable-gdkpixbuf*} == ""
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

pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can enable some features by defining following variables."
	@${ECHO_MSG} "===>"
.if !exists(${LOCALBASE}/bin/artsc-config) && !defined(WITH_ARTS) || defined(WITHOUT_ARTS)
	@${ECHO_MSG} "===> WITH_ARTS   (arts support)"
.else
	@${ECHO_MSG} "===> WITH_ARTS   (arts support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libcaca.a) && !defined(WITH_CACA) || defined(WITHOUT_CACA)
	@${ECHO_MSG} "===> WITH_CACA (libcaca support)"
.else
	@${ECHO_MSG} "===> WITH_CACA (libcaca support, enabled)"
.endif
.if !(${HAVE_GNOME:Mgnomevfs2} != "") && !defined(WITH_GNOMEVFS2) || defined(WITHOUT_GNOMEVFS2)
	@${ECHO_MSG} "===> WITH_GNOMEVFS2 (gnomevfs2 support)"
.else
	@${ECHO_MSG} "===> WITH_GNOMEVFS2 (gnomevfs2 support, enabled)"
.endif
.if !(${HAVE_GNOME:Mesound} != "") && !defined(WITH_ESOUND) || defined(WITHOUT_ESOUND)
	@${ECHO_MSG} "===> WITH_ESOUND (esound support)"
.else
	@${ECHO_MSG} "===> WITH_ESOUND (esound support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libjack.so) && !defined(WITH_JACK) || defined(WITHOUT_JACK)
	@${ECHO_MSG} "===> WITH_JACK (JACK support)"
.else
	@${ECHO_MSG} "===> WITH_JACK (JACK support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libpulse.so.0) && !defined(WITH_PULSEAUDIO) || defined(WITHOUT_PULSEAUDIO)
	@${ECHO_MSG} "===> WITH_PULSEAUDIO (pulseaudio support)"
.else
	@${ECHO_MSG} "===> WITH_PULSEAUDIO (pulseaudio support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libsmbclient.so.0) && !defined (WITH_SMB) || defined(WITHOUT_SMB)
	@${ECHO_MSG} "===> WITH_SMB (SMB support)"
.else
	@${ECHO_MSG} "===> WITH_SMB (SMB support, enabled)"
.endif
.if !exists(${X11BASE}/lib/libXvMCNVIDIA.so.1) && !defined(WITH_XVMC) || defined(WITHOUT_XVMC)
	@${ECHO_MSG} "===> WITH_XVMC (XvMC support)"
.else
	@${ECHO_MSG} "===> WITH_XVMC (XvMC support, enabled)"
.endif
	@${ECHO_MSG} "===>"

post-patch:
.for f in libtool ltmain.sh
	@${REINPLACE_CMD} -e \
		'/freebsd-elf)/,/;;/ s|major="\.$$current"|major=.`expr $$current - $$age`|; \
		/freebsd-elf)/,/;;/ s|versuffix="\.$$current"|versuffix="$$major"|' \
		${WRKSRC}/${f}
.endfor

pre-configure:
	@${REINPLACE_CMD} -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g ; \
		 s|-lgiconv|-liconv|g ; \
		 s|-funroll-loops||g ; \
		 s|LIBFFMPEG_CFLAGS|LIBFFMPEG_CPPFLAGS|g ; \
		 s|echo aout|echo elf|g' ${WRKSRC}/configure
.if ${OSVERSION} >= 500035
	@${REINPLACE_CMD} -e \
		 's|-malign-loops|-falign-loops|g ; \
		  s|-malign-jumps|-falign-jumps|g ; \
		  s|-malign-functions|-falign-functions|g' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
