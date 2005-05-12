# New ports collection makefile for:	amule
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	aMule
PORTVERSION=	2.0.0rc7
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/amule/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	The all-platform eMule p2p client

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24 \
		curl.3:${PORTSDIR}/ftp/curl \
		execinfo.1:${PORTSDIR}/devel/libexecinfo
#		gd.4:${PORTSDIR}/graphics/gd

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
CONFLICTS=	aMule-[0-9]*

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnomehack gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-debug \
		--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-wx-config=${WX_CONFIG} \
		--with-wxbase-config=${WX_CONFIG} \
		--with-curl-config=${CURL_CONFIG} \
		--enable-embedded_crypto \
		--enable-utf8-systray
#		--with-gdlib-prefix=${LOCALBASE} \
#		--with-gdlib-exec-prefix=${LOCALBASE}

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	OPTIMIZE "Build with optimization" on \
		ED2K "Compile aMule ed2k links handler" on \
		AMULECMD "Compile aMule command line client (+GUI)" on \
		AMULEWEBSRV "Compile aMule WebServer (+GUI)" on \
		CAS "Compile C aMule Statistics (+GUI)" on \
		ALC "Compile aMule Link Creator (+GUI)" on
#		AMULEDAEMON "Compile aMule daemon version (+GUI) - unsupported yet : needs wxGtk >= 2.5.1" on

WX_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
CURL_CONFIG?=	${LOCALBASE}/bin/curl-config

.include <bsd.port.pre.mk>

# Configure options
.if defined(WITH_OPTIMIZE)
CONFIGURE_ARGS+=	--enable-optimize
.else
CONFIGURE_ARGS+=	--disable-optimize
.endif

.if defined(WITH_ED2K)
CONFIGURE_ARGS+=	--enable-ed2k --program-transform-name="s/ed2k/amule-ed2k/"
PLIST_SUB+=		PL_ED2K=""
.else
CONFIGURE_ARGS+=	--disable-ed2k
PLIST_SUB+=		PL_ED2K="@comment "
.endif

.if defined(WITH_AMULECMD)
CONFIGURE_ARGS+=	--enable-amulecmd --enable-amulecmdgui
PLIST_SUB+=		PL_AMULECMD=""
.else
CONFIGURE_ARGS+=	--disable-amulecmd --disable-amulecmdgui
PLIST_SUB+=		PL_AMULECMD="@comment "
.endif

.if defined(WITH_AMULEWEBSRV)
CONFIGURE_ARGS+=	--enable-webserver --enable-webservergui
PLIST_SUB+=		PL_AMULEWEBSRV=""
.else
CONFIGURE_ARGS+=	--disable-webserver --disable-webservergui
PLIST_SUB+=		PL_AMULEWEBSRV="@comment "
.endif

.if defined(WITH_CAS)
CONFIGURE_ARGS+=	--enable-cas --enable-wxcas
PLIST_SUB+=		PL_CAS=""
.else
CONFIGURE_ARGS+=	--disable-cas --disable-wxcas
PLIST_SUB+=		PL_CAS="@comment "
.endif

.if defined(WITH_ALC)
CONFIGURE_ARGS+=	--enable-alc --enable-alcc
PLIST_SUB+=		PL_ALC=""
.else
CONFIGURE_ARGS+=	--disable-alc --disable-alcc
PLIST_SUB+=		PL_ALC="@comment "
.endif

#.if defined(WITH_AMULEDAEMON)
#CONFIGURE_ARGS+=	--enable-amule-daemon --enable-amule-gui
#PLIST_SUB+=		PL_AMULEDAEMON=""
#.else
#CONFIGURE_ARGS+=	--disable-amule-daemon --disable-amule-gui
#PLIST_SUB+=		PL_AMULEDAEMON="@comment "
#.endif

.include <bsd.port.post.mk>
