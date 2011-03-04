# New ports collection makefile for:	amule
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	amule
PORTVERSION=	2.2.6
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/aMule/${PORTVERSION}
DISTNAME=	aMule-${PORTVERSION}

MAINTAINER=	swell.k@gmail.com
COMMENT=	The all-platform eMule p2p client

BUILD_DEPENDS=	${FLEX}:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp

CONFLICTS=	amule-devel-[0-9]*

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=${WRKSRC}/docs/COPYING

USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_GMAKE=	yes
USE_WX=		2.8
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-denoise-level=0

CONFIGURE_ENV=	LEX="${FLEX}" PKG_CONFIG="${PKG_CONFIG}" \
		docdir='$${prefix}/${DOCSDIR_REL}' \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

OPTIONS=	ALC "Compile aMule Link Creator for GUI" on \
		ALCC "Compile aMule Link Creator for console" on \
		AMULECMD "Compile aMule command line client" on \
		AMULEDAEMON "Compile aMule daemon version" on \
		AMULEGUI "Compile aMule remote GUI (EXPERIMENTAL)" on \
		CAS "Compile aMule Statistics for console" on \
		ED2K "Compile aMule ed2k links handler" on \
		GEOIP "Enable GeoIP IP2Country support" off \
		MONOLITHIC "Compile monolithic aMule" on \
		UPNP "Enable Universal Plug and Play support" off \
		WEBSERVER "Compile aMule WebServer" on \
		WXCAS "Compile aMule Statistics for GUI" on \
		WXUNICODE "Enable Unicode support" on

PORTDOCS=	ABOUT-NLS Changelog EC_Protocol.txt \
		ED2K-Links.HOWTO INSTALL README TODO \
		amule-win32.HOWTO.txt amulesig.txt license.txt socks4.protocol

FLEX?=		${LOCALBASE}/bin/flex
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_ALC)
CONFIGURE_ARGS+=	--enable-alc
PLIST_SUB+=		ALC=""
.else
CONFIGURE_ARGS+=	--disable-alc
PLIST_SUB+=		ALC="@comment "
.endif

.if !defined(WITHOUT_ALCC)
CONFIGURE_ARGS+=	--enable-alcc
PLIST_SUB+=		ALCC=""
.else
CONFIGURE_ARGS+=	--disable-alcc
PLIST_SUB+=		ALCC="@comment "
.endif

.if !defined(WITHOUT_AMULECMD)
CONFIGURE_ARGS+=	--enable-amulecmd
PLIST_SUB+=		AMULECMD=""
.else
CONFIGURE_ARGS+=	--disable-amulecmd
PLIST_SUB+=		AMULECMD="@comment "
.endif

.if !defined(WITHOUT_AMULEDAEMON)
CONFIGURE_ARGS+=	--enable-amule-daemon
PLIST_SUB+=		AMULEDAEMON=""
USE_RC_SUBR=		amuled.sh
.else
CONFIGURE_ARGS+=	--disable-amule-daemon
PLIST_SUB+=		AMULEDAEMON="@comment "
.endif

.if !defined(WITHOUT_AMULEGUI)
CONFIGURE_ARGS+=	--enable-amule-gui
PLIST_SUB+=		AMULEGUI=""
.else
CONFIGURE_ARGS+=	--disable-amule-gui
PLIST_SUB+=		AMULEGUI="@comment "
.endif

.if !defined(WITHOUT_CAS)
CONFIGURE_ARGS+=	--enable-cas
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=		CAS=""
.else
CONFIGURE_ARGS+=	--disable-cas
PLIST_SUB+=		CAS="@comment "
.endif

.if !defined(WITHOUT_ED2K)
CONFLICTS+=		ed2k-hash*
CONFIGURE_ARGS+=	--enable-ed2k
PLIST_SUB+=		ED2K=""
.else
CONFIGURE_ARGS+=	--disable-ed2k
PLIST_SUB+=		ED2K="@comment "
.endif

.if !defined(WITHOUT_GEOIP)
CONFIGURE_ARGS+=	--enable-geoip
LIB_DEPENDS+=		GeoIP.5:${PORTSDIR}/net/GeoIP
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if !defined(WITHOUT_MONOLITHIC)
CONFIGURE_ARGS+=	--enable-monolithic
PLIST_SUB+=		MONOLITHIC=""
.else
CONFIGURE_ARGS+=	--disable-monolithic
PLIST_SUB+=		MONOLITHIC="@comment "
.endif

.if !defined(WITHOUT_UPNP)
LIB_DEPENDS+=		upnp.6:${PORTSDIR}/devel/upnp
.else
CONFIGURE_ARGS+=	--disable-upnp
.endif

.if !defined(WITHOUT_WEBSERVER)
CONFIGURE_ARGS+=	--enable-webserver
PLIST_SUB+=		WEBSERVER=""
.else
CONFIGURE_ARGS+=	--disable-webserver
PLIST_SUB+=		WEBSERVER="@comment "
.endif

.if !defined(WITHOUT_WXCAS)
CONFIGURE_ARGS+=	--enable-wxcas
PLIST_SUB+=		WXCAS=""
.else
CONFIGURE_ARGS+=	--disable-wxcas
PLIST_SUB+=		WXCAS="@comment "
.endif

.if !defined(WITHOUT_WXUNICODE)
WX_UNICODE=		yes
.endif

# Man pages management
.include "Makefile.man"

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LDFLAGS/s/-lpthread/${PTHREAD_LIBS}/' \
		-e 's/test.*-print-file-name.*`/true/' \
		${WRKSRC}/configure
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' \
		${WRKSRC}/docs/Makefile.in
.endif

post-install:
	-update-desktop-database ${PREFIX}/share/applications

.include <bsd.port.post.mk>
