# New ports collection makefile for:	amule2
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	aMule
PORTVERSION=	2.1.3
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	amule

PATCH_SITES=	http://cvs.pld-linux.org/cgi-bin/cvsweb/SOURCES/
PATCHFILES=	aMule-wx.patch?rev=1.2
PATCH_DIST_STRIP=	-p1

MAINTAINER=	boris@tagnet.ru
COMMENT=	The all-platform eMule p2p client

LATEST_LINK=	aMule2
CONFLICTS=	aMule-1.* aMule-devel-[0-9]*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnomehack gnomeprefix
USE_GMAKE=	yes
USE_WX=		2.8
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-debug \
		--mandir=${MANPREFIX}/man \
		--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--enable-embedded_crypto

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	OPTIMIZE "Build with optimization" on \
		ED2K "Compile aMule ed2k links handler" on \
		AMULECMD "Compile aMule command line client" on \
		AMULEWEBSRV "Compile aMule WebServer" on \
		CAS "Compile C aMule Statistics (+GUI)" on \
		ALC "Compile aMule Link Creator (+GUI)" on \
		AMULEDAEMON "Compile aMule daemon version - EXPERIMENTAL" off \
		WXUNICODE "Enable Unicode support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Will not compile on FreeBSD 4.x - See net-p2p/amule1 for 4.x compatibility
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

# Configure options
.if !defined(WITHOUT_OPTIMIZE)
CONFIGURE_ARGS+=	--enable-optimize
.else
CONFIGURE_ARGS+=	--disable-optimize
.endif

.if !defined(WITHOUT_ED2K)
CONFIGURE_ARGS+=	--enable-ed2k
PLIST_SUB+=		PL_ED2K=""
.else
CONFIGURE_ARGS+=	--disable-ed2k
PLIST_SUB+=		PL_ED2K="@comment "
.endif

.if !defined(WITHOUT_AMULECMD)
CONFIGURE_ARGS+=	--enable-amulecmd
PLIST_SUB+=		PL_AMULECMD=""
.else
CONFIGURE_ARGS+=	--disable-amulecmd
PLIST_SUB+=		PL_AMULECMD="@comment "
.endif

.if !defined(WITHOUT_AMULEWEBSRV)
CONFIGURE_ARGS+=	--enable-webserver
PLIST_SUB+=		PL_AMULEWEBSRV=""
.else
CONFIGURE_ARGS+=	--disable-webserver
PLIST_SUB+=		PL_AMULEWEBSRV="@comment "
.endif

.if !defined(WITHOUT_CAS)
CONFIGURE_ARGS+=	--enable-cas --enable-wxcas
PLIST_SUB+=		PL_CAS=""
.else
CONFIGURE_ARGS+=	--disable-cas --disable-wxcas
PLIST_SUB+=		PL_CAS="@comment "
.endif

.if !defined(WITHOUT_ALC)
CONFIGURE_ARGS+=	--enable-alc --enable-alcc
PLIST_SUB+=		PL_ALC=""
.else
CONFIGURE_ARGS+=	--disable-alc --disable-alcc
PLIST_SUB+=		PL_ALC="@comment "
.endif

.if defined(WITH_AMULEDAEMON)
CONFIGURE_ARGS+=	--enable-amule-daemon --enable-amule-gui
PLIST_SUB+=		PL_AMULEDAEMON=""
USE_RC_SUBR=		amuled.sh
.else
CONFIGURE_ARGS+=	--disable-amule-daemon --disable-amule-gui
PLIST_SUB+=		PL_AMULEDAEMON="@comment "
.endif

.if !defined(WITHOUT_WXUNICODE)
WX_UNICODE=yes
.endif

# Man pages management
.include "Makefile.man"

post-install:
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

.include <bsd.port.post.mk>
