# New ports collection makefile for:	amule2
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	aMule
PORTVERSION=	2.0.0
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/amule/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	The all-platform eMule p2p client

LIB_DEPENDS=	wx_gtk2u_core-2.6:${PORTSDIR}/x11-toolkits/wxgtk26-unicode \
		curl.3:${PORTSDIR}/ftp/curl
#		gd.4:${PORTSDIR}/graphics/gd
#		png.5:${PORTSDIR}/graphics/png

LATEST_LINK=	aMule2
CONFLICTS=	aMule-1.* aMule-devel-[0-9]*

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
		--enable-utf8-systray \
		--enable-monolithic
#		--with-gdlib-prefix=${LOCALBASE} \
#		--with-libpng-prefix=${LOCALBASE}

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	OPTIMIZE "Build with optimization" on \
		ED2K "Compile aMule ed2k links handler" on \
		AMULECMD "Compile aMule command line client (+GUI)" on \
		AMULEWEBSRV "Compile aMule WebServer (+GUI)" on \
		CAS "Compile C aMule Statistics (+GUI)" on \
		ALC "Compile aMule Link Creator (+GUI)" on \
		AMULEDAEMON "Compile aMule daemon version - EXPERIMENTAL" off

WX_CONFIG?=	${X11BASE}/bin/wxgtk2u-2.6-config
CURL_CONFIG?=	${LOCALBASE}/bin/curl-config

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Won't compile on FreeBSD 4.x - See net/amule1 for 4.x compatibility."
.endif

# Configure options
.if defined(WITH_OPTIMIZE)
CONFIGURE_ARGS+=	--enable-optimize
.else
CONFIGURE_ARGS+=	--disable-optimize
.endif

.if defined(WITH_ED2K)
CONFIGURE_ARGS+=	--enable-ed2k
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

.if defined(WITH_AMULEDAEMON)
CONFIGURE_ARGS+=	--enable-amule-daemon --enable-amule-gui
PLIST_SUB+=		PL_AMULEDAEMON=""
USE_RC_SUBR=		yes
RCSCRIPT=		${PREFIX}/etc/rc.d/amuled.sh
.else
CONFIGURE_ARGS+=	--disable-amule-daemon --disable-amule-gui
PLIST_SUB+=		PL_AMULEDAEMON="@comment "
.endif

# Man pages management
.include "Makefile.man"

# Copy startup script if needed (amuledaemon compiled)
post-install:
.if defined(WITH_AMULEDAEMON)
	${ECHO} "Installing ${RCSCRIPT} startup file."
	${INSTALL_SCRIPT} ${FILESDIR}/amuled.sh ${RCSCRIPT}
.endif

# fr manpages are still incomplete and can't be managed
# by MANLANG. Will be done when pages are complete.
.if defined(WITH_AMULECMD)
	${GZIP_CMD} ${PREFIX}/man/fr/man1/amulecmd.1
.endif
.if defined(WITH_AMULEWEBSRV)
	${GZIP_CMD} ${PREFIX}/man/fr/man1/amuleweb.1
.endif
	${GZIP_CMD} ${PREFIX}/man/fr/man1/amule.1
.if defined(WITH_AMULEDAEMON)
	${GZIP_CMD} ${PREFIX}/man/fr/man1/amuled.1
.endif
.if defined(WITH_ED2K)
	${GZIP_CMD} ${PREFIX}/man/fr/man1/ed2k.1
.endif
.if defined(WITH_ALC)
	${GZIP_CMD} ${PREFIX}/man/fr/man1/alcc.1
.endif
.if defined(WITH_AMULECMD)
	${RM} ${PREFIX}/man/fr/man1/amulecmdDLG.1
	${LN} ${PREFIX}/man/fr/man1/amulecmd.1.gz ${PREFIX}/man/fr/man1/amulecmdDLG.1.gz
.endif
.if defined(WITH_AMULEWEBSRV)
	${RM} ${PREFIX}/man/fr/man1/amulewebDLG.1
	${LN} ${PREFIX}/man/fr/man1/amuleweb.1.gz ${PREFIX}/man/fr/man1/amulewebDLG.1.gz
.endif

.include <bsd.port.post.mk>
