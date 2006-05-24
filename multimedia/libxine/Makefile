# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	multimedia ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

BUILD_DEPENDS=	${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		speex.3:${PORTSDIR}/audio/speex \
		aa.1:${PORTSDIR}/graphics/aalib \
		mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fame-0.9.1:${PORTSDIR}/multimedia/libfame \
		cdio.7:${PORTSDIR}/sysutils/libcdio \
		modplug.0:${PORTSDIR}/audio/libmodplug \
		vcdinfo.2:${PORTSDIR}/multimedia/vcdimager \
		Wand.9:${PORTSDIR}/graphics/ImageMagick

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fno-force-addr -I${LOCALBASE}/include -I${LOCALBASE}/include/dvdread -I${X11BASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}" \
		EXTRA_X_LIBS="-lGL -lGLU -lXext -lX11 -lm"
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32 --enable-ipv6
INSTALLS_SHLIB=	yes

MAN1=	xine-config.1
MAN5=	xine.5

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
PLIST_SUB+=	WITH_LIBXV=""
.else
PLIST_SUB+=	WITH_LIBXV="@comment "
.endif

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
CONFIGURE_ARGS+=	--disable-esd --disable-esdtest
.endif

.if !defined(WITHOUT_GNOMEVFS2) && (${HAVE_GNOME:Mgnomevfs2} != "" || defined(WITH_GNOMEVFS2))
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	WITH_GNOMEVFS2=""
.else
PLIST_SUB+=	WITH_GNOMEVFS2="@comment "
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if !defined(WITHOUT_POLYPAUDIO) && (exists(${LOCALBASE}/lib/libpolyp-0.7.so.0) || defined(WITH_POLYPAUDIO))
LIB_DEPENDS+=	polyp-0.7.0:${PORTSDIR}/audio/polypaudio
PLIST_SUB+=	WITH_POLYPAUDIO=""
.else
PLIST_SUB+=	WITH_POLYPAUDIO="@comment "
CONFIGURE_ARGS+=	--disable-polypaudio
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	WITH_VIDIX=""
.else
PLIST_SUB+=	WITH_VIDIX="@comment "
CONFIGURE_ARGS+=	--disable-vidix
.endif

.if !defined(WITHOUT_XVMC) && (exists(${X11BASE}/lib/libXvMCNVIDIA.so.1) || defined(WITH_XVMC))
CONFIGURE_ARGS+=--with-xvmc-lib=XvMCNVIDIA
LIB_DEPENDS+=	XvMCNVIDIA.1:${PORTSDIR}/x11/nvidia-driver
PLIST_SUB+=	WITH_XVMC=""
.else
PLIST_SUB+=	WITH_XVMC="@comment "
.endif

.if !defined(WITHOUT_THEORA) && (exists(${LOCALBASE}/lib/libtheora.so.2) || defined (WITH_THEORA))
LIB_DEPENDS+=	theora.2:${PORTSDIR}/multimedia/libtheora
PLIST_SUB+=	WITH_THEORA=""
.else
PLIST_SUB+=	WITH_THEORA="@comment "
CONFIGURE_ARGS+=	--disable-theoratest
.endif

.if !defined(WITHOUT_SMB) && (exists(${LOCALBASE}/lib/libsmbclient.so.0) || defined (WITH_SMB))
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	WITH_SMB=""
.else
PLIST_SUB+=	WITH_SMB="@comment "
CONFIGURE_ARGS+=	--disable-samba
.endif

pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can enable some features by defining following variables."
	@${ECHO_MSG} "===>"
.if !exists(${LOCALBASE}/bin/artsc-config) && !defined(WITH_ARTS)
	@${ECHO_MSG} "===> WITH_ARTS   (arts support)"
.else
	@${ECHO_MSG} "===> WITH_ARTS   (arts support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libcaca.a) && !defined(WITH_CACA)
	@${ECHO_MSG} "===> WITH_CACA (libcaca support)"
.else
	@${ECHO_MSG} "===> WITH_CACA (libcaca support, enabled)"
.endif
.if !(${HAVE_GNOME:Mgnomevfs2} != "") && !defined(WITH_GNOMEVFS2)
	@${ECHO_MSG} "===> WITH_GNOMEVFS2 (gnomevfs2 support)"
.else
	@${ECHO_MSG} "===> WITH_GNOMEVFS2 (gnomevfs2 support, enabled)"
.endif
.if !(${HAVE_GNOME:Mesound} != "") && !defined(WITH_ESOUND)
	@${ECHO_MSG} "===> WITH_ESOUND (esound support)"
.else
	@${ECHO_MSG} "===> WITH_ESOUND (esound support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libpolyp-0.7.so.0) && !defined(WITH_POLYPAUDIO)
	@${ECHO_MSG} "===> WITH_POLYPAUDIO (polypaudio support)"
.else
	@${ECHO_MSG} "===> WITH_POLYPAUDIO (polypaudio support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libsmbclient.so.0) && !defined (WITH_SMB)
	@${ECHO_MSG} "===> WITH_SMB (SMB support)"
.else
	@${ECHO_MSG} "===> WITH_SMB (SMB support, enabled)"
.endif
.if !exists(${LOCALBASE}/lib/libtheora.so.2) && !defined(WITH_THEORA)
	@${ECHO_MSG} "===> WITH_THEORA (libtheora support)"
.else
	@${ECHO_MSG} "===> WITH_THEORA (libtheora support, enabled)"
.endif
.if !exists(${X11BASE}/lib/libXvMCNVIDIA.so.1) && !defined(WITH_XVMC)
	@${ECHO_MSG} "===> WITH_XVMC (XvMC support)"
.else
	@${ECHO_MSG} "===> WITH_XVMC (XvMC support, enabled)"
.endif
	@${ECHO_MSG} "===>"

post-patch:
	@${REINPLACE_CMD} -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g ; \
		 s|-lgiconv|-liconv|g ; \
		 s|-funroll-loops||g' ${WRKSRC}/configure
.if ${OSVERSION} >= 500035
	@${REINPLACE_CMD} -e \
		 's|-malign-loops|-falign-loops|g ; \
		  s|-malign-jumps|-falign-jumps|g ; \
		  s|-malign-functions|-falign-functions|g' ${WRKSRC}/configure
.endif

pre-build:
	${CP} ${LTMAIN} ${WRKSRC}/ltmain.sh

.include <bsd.port.post.mk>
