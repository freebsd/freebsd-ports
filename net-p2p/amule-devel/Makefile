# New ports collection makefile for:	amule-devel
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	amule
PORTVERSION=	10788
CATEGORIES=	net-p2p
MASTER_SITES=	http://amule.sourceforge.net/tarballs/
PKGNAMESUFFIX=	-devel
DISTNAME=	aMule-SVN-r${PORTVERSION}

MAINTAINER=	barbara.xxx1975@libero.it
COMMENT=	The all-platform eMule p2p client

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LICENSE_FILE_GPLv2=${WRKSRC}/docs/COPYING

BUILD_DEPENDS=	${FLEX}:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp

CONFLICTS=	amule-[0-9]*

USE_BZIP2=	yes
USE_BISON=	build
USE_GNOME=	pkgconfig
USE_GMAKE=	yes
USE_WX=		2.8
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-denoise-level=0

CONFIGURE_ENV=	LEX="${FLEX}" PKG_CONFIG="${PKG_CONFIG}" \
		docdir='$${prefix}/${DOCSDIR_REL}'

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

OPTIONS_DEFINE=	ALC ALCC AMULECMD AMULEDAEMON AMULEGUI CAS DEBUG ED2K FILEVIEW \
	GEOIP MMAP MONOLITHIC OPTIMIZED_CFLAGS PLASMAMULE UPNP WEBSERVER WXCAS \
	WXUNICODE XAS
ALC_DESC=		"Compile aMule Link Creator for GUI"
ALCC_DESC=		"Compile aMule Link Creator for console"
AMULECMD_DESC=		"Compile aMule command line client"
AMULEDAEMON_DESC=	"Compile aMule daemon version"
AMULEGUI_DESC=		"Compile aMule remote GUI"
CAS_DESC=		"Compile aMule Statistics for console"
DEBUG_DESC=		"Compile aMule with additional debugging output"
ED2K_DESC=		"Compile aMule ed2k links handler"
FILEVIEW_DESC=		"Compile file viewer for console (EXPERIMENTAL)"
GEOIP_DESC=		"Enable GeoIP IP2Country support"
MMAP_DESC=		"Enable using mapped memory"
MONOLITHIC_DESC=	"Compile monolithic aMule"
PLASMAMULE_DESC=	"Compile aMule plasma applet and engine"
UPNP_DESC=		"Enable Universal Plug and Play support"
WEBSERVER_DESC=		"Compile aMule WebServer"
WXCAS_DESC=		"Compile aMule Statistics for GUI"
WXUNICODE_DESC=		"Enable Unicode support"
XAS_DESC=		"Install XChat2 plugin"
OPTIONS_DEFAULT=ALC ALCC AMULECMD AMULEDAEMON AMULEGUI CAS ED2K FILEVIEW \
	MONOLITHIC WEBSERVER WXCAS WXUNICODE XAS

PORTDOCS=	ABOUT-NLS Changelog EC_Protocol.txt INSTALL README TODO \
		amulesig.txt license.txt

FLEX?=		${LOCALBASE}/bin/flex
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MALC}
CONFIGURE_ARGS+=	--enable-alc
PLIST_SUB+=		ALC=""
.else
CONFIGURE_ARGS+=	--disable-alc
PLIST_SUB+=		ALC="@comment "
.endif

.if ${PORT_OPTIONS:MALCC}
CONFIGURE_ARGS+=	--enable-alcc
PLIST_SUB+=		ALCC=""
.else
CONFIGURE_ARGS+=	--disable-alcc
PLIST_SUB+=		ALCC="@comment "
.endif

.if ${PORT_OPTIONS:MAMULECMD}
CONFIGURE_ARGS+=	--enable-amulecmd
PLIST_SUB+=		AMULECMD=""
.else
CONFIGURE_ARGS+=	--disable-amulecmd
PLIST_SUB+=		AMULECMD="@comment "
.endif

.if ${PORT_OPTIONS:MAMULEDAEMON}
CONFIGURE_ARGS+=	--enable-amule-daemon
PLIST_SUB+=		AMULEDAEMON=""
USE_RC_SUBR=		amuled
.else
CONFIGURE_ARGS+=	--disable-amule-daemon
PLIST_SUB+=		AMULEDAEMON="@comment "
.endif

.if ${PORT_OPTIONS:MAMULEGUI}
CONFIGURE_ARGS+=	--enable-amule-gui
PLIST_SUB+=		AMULEGUI=""
.else
CONFIGURE_ARGS+=	--disable-amule-gui
PLIST_SUB+=		AMULEGUI="@comment "
.endif

.if ${PORT_OPTIONS:MCAS}
CONFIGURE_ARGS+=	--enable-cas
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=		CAS=""
.else
CONFIGURE_ARGS+=	--disable-cas
PLIST_SUB+=		CAS="@comment "
.endif

.if ${PORT_OPTIONS:MED2K}
CONFLICTS+=		ed2k-hash*
CONFIGURE_ARGS+=	--enable-ed2k
PLIST_SUB+=		ED2K=""
.else
CONFIGURE_ARGS+=	--disable-ed2k
PLIST_SUB+=		ED2K="@comment "
.endif

.if ${PORT_OPTIONS:MFILEVIEW}
CONFIGURE_ARGS+=	--enable-fileview
PLIST_SUB+=		FILEVIEW=""
.else
CONFIGURE_ARGS+=	--disable-fileview
PLIST_SUB+=		FILEVIEW="@comment "
.endif

.if ${PORT_OPTIONS:MGEOIP}
CONFIGURE_ARGS+=	--enable-geoip
LIB_DEPENDS+=		GeoIP.5:${PORTSDIR}/net/GeoIP
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if ${PORT_OPTIONS:MMMAP}
CONFIGURE_ARGS+=	--enable-mmap
.else
CONFIGURE_ARGS+=	--disable-mmap
.endif

.if ${PORT_OPTIONS:MMONOLITHIC}
CONFIGURE_ARGS+=	--enable-monolithic
PLIST_SUB+=		MONOLITHIC=""
.else
CONFIGURE_ARGS+=	--disable-monolithic
PLIST_SUB+=		MONOLITHIC="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CONFIGURE_ARGS+=	--enable-optimize
.endif

.if ${PORT_OPTIONS:MPLASMAMULE}
CONFIGURE_ENV+=		ac_cv_path_KDE4_CONFIG=${KDE4_PREFIX}/bin/kde4-config \
			KBUILDSYCOCA=${KDE4_PREFIX}/bin/kbuildsycoca4 \
			UPDATE_MIME_DATABASE=/usr/bin/true
CONFIGURE_ARGS+=	--enable-plasmamule
USE_KDE4=		kdelibs
USE_QT4=		dbus gui moc_build
PLIST_SUB+=		PLASMAMULE=""
.else
CONFIGURE_ARGS+=	--disable-plasmamule
PLIST_SUB+=		PLASMAMULE="@comment "
.endif

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=		upnp.9:${PORTSDIR}/devel/upnp
.else
CONFIGURE_ARGS+=	--disable-upnp
.endif

.if ${PORT_OPTIONS:MWEBSERVER}
CONFIGURE_ARGS+=	--enable-webserver
PLIST_SUB+=		WEBSERVER=""
.else
CONFIGURE_ARGS+=	--disable-webserver
PLIST_SUB+=		WEBSERVER="@comment "
.endif

.if ${PORT_OPTIONS:MWXCAS}
CONFIGURE_ARGS+=	--enable-wxcas
PLIST_SUB+=		WXCAS=""
.else
CONFIGURE_ARGS+=	--disable-wxcas
PLIST_SUB+=		WXCAS="@comment "
.endif

.if ${PORT_OPTIONS:MWXUNICODE}
WX_UNICODE=		yes
.endif

.if ${PORT_OPTIONS:MXAS}
CONFIGURE_ARGS+=	--enable-xas
PLIST_SUB+=		XAS=""
.else
CONFIGURE_ARGS+=	--disable-xas
PLIST_SUB+=		XAS="@comment "
.endif

# Man pages management
.include "Makefile.man"

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LDFLAGS/s/-lpthread/${PTHREAD_LIBS}/' \
		-e 's/test.*-print-file-name.*`/true/' \
		-e '/if.*test/s/==/=/' \
		${WRKSRC}/configure
	${FIND} ${WRKSRC} -name \*.pl -exec ${REINPLACE_CMD} \
		's|/usr/bin/perl|${PERL}|' {} +
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' \
		${WRKSRC}/docs/Makefile.in
.endif
.if ${PORT_OPTIONS:MPLASMAMULE}
	${REINPLACE_CMD} -e 's|@prefix@|${KDE4_PREFIX}|' \
		-e 's|LDFLAGS =|& -L${KDE4_PREFIX}/lib |' \
		${WRKSRC}/src/utils/plasmamule/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MFILEVIEW}
	${INSTALL_PROGRAM} ${WRKSRC}/src/utils/fileview/mulefileview ${PREFIX}/bin
.endif
.if exists(${LOCALBASE}/bin/update-desktop-database)
. if ${PORT_OPTIONS:MPLASMAMULE}
	-update-desktop-database ${KDE4_PREFIX}/share/applications
.  if exists(${LOCALBASE}/bin/update-mime-database)
	-update-mime-database ${KDE4_PREFIX}/share/mime
.  endif
. endif
	-update-desktop-database ${PREFIX}/share/applications
.endif

.include <bsd.port.mk>
