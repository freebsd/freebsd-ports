# New ports collection makefile for:	x264
# Date created:		2005-01-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#      $Id: Makefile 30 2006-10-30 22:15:26Z buhnux $

PORTNAME=	x264
PORTVERSION=	0.0.20070331
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.videolan.org/pub/videolan/x264/snapshots/
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION:S/0.0.//}-2245

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Multimedia library and tool for encoding H.264/AVC video streams

WANT_GNOME=	yes
USE_BZIP2=	yes
EXTRACT_AFTER_ARGS?=	| ${TAR} -xf - --exclude .svn
USE_GETOPT_LONG=yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
ALL_TARGET=	default
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

OPTIONS=	GPAC "Enable MPEG-4 Output" On \
		GTK2 "Enable GTK2+ Frontend" On \
		DEBUG "Enable Debugging" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off \
		X11_OUTPUT "Enable X11 Output" Off

CONFIGURE_ARGS+=	--extra-cflags="${CPPFLAGS} ${CFLAGS} -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
			--extra-ldflags="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib" \
			--enable-shared

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GTK2) || ${HAVE_GNOME:Mgtk20}!=""
USE_GETTEXT=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--enable-gtk
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if ${ARCH}=="i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ENV+=	ARCH_X86="1"
.endif

.if ${ARCH}=="amd64" || ${ARCH}=="sparc64"
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
MAKE_ENV+=	ARCH_X86_64="1"
.endif

MAKE_ARGS+=	ARCH=${ARCH}

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -funroll-loops -ffast-math
.endif

.if !defined(WITHOUT_GPAC)
BUILD_DEPENDS+=		gpac-libgpac>=0.4.2.r2,1:${PORTSDIR}/multimedia/gpac-libgpac
LIB_DEPENDS+=		gpac.1:${PORTSDIR}/multimedia/gpac-libgpac
CONFIGURE_ARGS+=	--enable-mp4-output
.endif

.if defined(WITH_X11_OUTPUT)
CONFIGURE_ARGS+=	--enable-visualize
USE_XLIB=		yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|; \
		s|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/*/Makefile

pre-install:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/x264.pc

.include <bsd.port.post.mk>
