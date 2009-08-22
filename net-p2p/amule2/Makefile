# New ports collection makefile for:	amule2
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	aMule
PORTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	boris@tagnet.ru
COMMENT=	The all-platform eMule p2p client

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp

LATEST_LINK=	aMule2
CONFLICTS=	aMule-1.* aMule-devel-[0-9]* ed2k-hash-1.*

USE_BZIP2=	yes
USE_GNOME=	gnomehier gnomehack gnomeprefix
USE_GMAKE=	yes
USE_WX=		2.8
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug \
		--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-crypto-prefix=${LOCALBASE} \
		--disable-upnp \
		--with-denoise-level=0

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	OPTIMIZE "Build with optimization" on \
		ED2K "Compile aMule ed2k links handler" on \
		AMULECMD "Compile aMule command line client" on \
		AMULEWEBSRV "Compile aMule WebServer" on \
		CAS "Compile C aMule Statistics (+GUI)" on \
		ALC "Compile aMule Link Creator (+GUI)" on \
		AMULEDAEMON "Compile aMule daemon version - EXPERIMENTAL" off \
		WXUNICODE "Enable Unicode support" on \
		GEOIP "Enable GeoIP IP2Country support" off \
		UPNP "Enable Universal Plug and Play support" off

DOCSDIR=	${PREFIX}/share/doc/aMule-${PORTVERSION}
PORTDOCS=	ABOUT-NLS Changelog EC_Protocol.txt \
		ED2K-Links.HOWTO INSTALL README TODO \
		amule-win32.HOWTO.txt amulesig.txt license.txt socks4.protocol

.include <bsd.port.pre.mk>

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

.if defined(WITH_GEOIP)
CONFIGURE_ARGS+=	--enable-geoip
LIB_DEPENDS+=		GeoIP.5:${PORTSDIR}/net/GeoIP
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if defined(WITH_UPNP)
CONFIGURE_ARGS+=	--with-libupnp-prefix=${LOCALBASE}
LIB_DEPENDS+=		upnp.3:${PORTSDIR}/devel/upnp
.else
CONFIGURE_ARGS+=	--disable-upnp
.endif

.if !defined(WITHOUT_WXUNICODE)
WX_UNICODE=yes
.endif

# Man pages management
.include "Makefile.man"

.ifdef NOPORTDOCS
post-patch:
	${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' ${WRKSRC}/docs/Makefile.in
.endif

.include <bsd.port.post.mk>
