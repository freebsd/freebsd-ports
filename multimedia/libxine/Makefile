# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	1.0.r3
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-1-rc3a

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Libraries for xine multimedia player

BUILD_DEPENDS=	${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
LIB_DEPENDS=	FLAC.5:${PORTSDIR}/audio/flac \
		a52.0:${PORTSDIR}/audio/liba52 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		mad.2:${PORTSDIR}/audio/libmad \
		speex.2:${PORTSDIR}/audio/speex \
		iconv.3:${PORTSDIR}/converters/libiconv \
		aa.1:${PORTSDIR}/graphics/aalib \
		mng.1:${PORTSDIR}/graphics/libmng \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/dvdread -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}" \
		X_EXTRA_LIBS="-lGL -lGLU -lXext -lX11 -lm"
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32 --enable-ipv6
INSTALLS_SHLIB=	yes

MAN1=		xine-config.1

.include <bsd.port.pre.mk>

# PRId64 macro is not defined
.if ${OSVERSION} < 500028
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src:xine-engine:audio_out.c
.endif

# FBIOVERTICAL macro is not defined
.if ${OSVERSION} < 500023
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src:video_out:Makefile.in
PLIST_SUB+=	PGX64="@comment "
.else
PLIST_SUB+=	PGX64=""
.endif

# CDIOCREADAUDIO macro is not defined
.if ${OSVERSION} >= 501106
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src:input:input_cdda.c
.endif

.if ${XFREE86_VERSION} >= 4
PLIST_SUB+=	HAVE_LIBXV=""
.else
PLIST_SUB+=	HAVE_LIBXV="@comment "
.endif

.if exists(${LOCALBASE}/bin/artsc-config) || defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	HAVE_ARTS=""
.else
PLIST_SUB+=	HAVE_ARTS="@comment "
.endif

.if ${HAVE_GNOME:Mesound} != "" || defined(WITH_ESOUND)
USE_GNOME+=	esound
PLIST_SUB+=	HAVE_ESOUND=""
.else
PLIST_SUB+=	HAVE_ESOUND="@comment "
.endif

.if ${HAVE_GNOME:Mgnomevfs2} != ""
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	HAVE_GNOMEVFS2=""
.else
PLIST_SUB+=	HAVE_GNOMEVFS2="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	VIDIX=""
.else
PLIST_SUB+=	VIDIX="@comment "
.endif

.if exists(${X11BASE}/lib/libXvMCNVIDIA.so.1)
LIB_DEPENDS+=	XvMCNVIDIA.1:${PORTSDIR}/x11/nvidia-driver
PLIST_SUB+=	XVMC=""
.else
PLIST_SUB+=	XVMC="@comment "
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
.if !(${HAVE_GNOME:Mesound} != "") && !defined(WITH_ESOUND)
	@${ECHO_MSG} "===> WITH_ESOUND (esound support)"
.else
	@${ECHO_MSG} "===> WITH_ESOUND (esound support, enabled)"
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

.include <bsd.port.post.mk>
