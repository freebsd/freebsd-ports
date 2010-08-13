# New ports collection makefile for:	amule2
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	aMule
PORTVERSION=	10266
CATEGORIES=	net-p2p
MASTER_SITES=	ftp://ftp.lissyara.su/users/Guest/distfiles/ \
		http://repo.or.cz/w/${PORTNAME:L}.git/snapshot/
DISTNAME=	${PORTNAME:L}-svn-r${PORTVERSION}

MAINTAINER=	swell.k@gmail.com
COMMENT=	The all-platform eMule p2p client

BUILD_DEPENDS=	${FLEX}:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp

LATEST_LINK=	aMule2
CONFLICTS=	aMule-1.* aMule-devel-[0-9]* ed2k-hash-1.*

WRKSRC=		${WRKDIR}/${PORTNAME:L}

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
USE_KDE4=	# empty
USE_QT_VER=	4
USE_WX=		2.8
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-crypto-prefix=${LOCALBASE} \
		--with-denoise-level=0

CONFIGURE_ENV=	LEX="${FLEX}" PKG_CONFIG="${PKG_CONFIG}" \
		docdir='$${prefix}/${DOCSDIR_REL}' \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

OPTIONS=	ALC "Compile aMule Link Creator (+GUI)" on \
		AMULECMD "Compile aMule command line client" on \
		AMULEDAEMON "Compile aMule daemon version" on \
		AMULEGUI "Compile aMule remote GUI (EXPERIMENTAL)" on \
		CAS "Compile C aMule Statistics (+GUI)" on \
		ED2K "Compile aMule ed2k links handler" on \
		GEOIP "Enable GeoIP IP2Country support" off \
		MMAP "Enable using mapped memory" off \
		PLASMAMULE "Compile aMule plasma applet and engine" off \
		UPNP "Enable Universal Plug and Play support" off \
		WEBSERVER "Compile aMule WebServer" on \
		WXUNICODE "Enable Unicode support" on \
		XAS "Install XChat2 plugin" on

DATADIR_REL=	share/${PORTNAME:L}
DOCSDIR_REL=	share/doc/${PORTNAME:L}
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
CONFIGURE_ARGS+=	--enable-alc --enable-alcc
PLIST_SUB+=		ALC=""
.else
CONFIGURE_ARGS+=	--disable-alc --disable-alcc
PLIST_SUB+=		ALC="@comment "
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
USE_RC_SUBR=		amuled.sh
.else
CONFIGURE_ARGS+=	--disable-amule-gui
PLIST_SUB+=		AMULEGUI="@comment "
.endif

.if !defined(WITHOUT_CAS)
CONFIGURE_ARGS+=	--enable-cas --enable-wxcas
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=		CAS=""
.else
CONFIGURE_ARGS+=	--disable-cas --disable-wxcas
PLIST_SUB+=		CAS="@comment "
.endif

.if !defined(WITHOUT_ED2K)
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

.if !defined(WITHOUT_MMAP)
CONFIGURE_ARGS+=	--enable-mmap
.else
CONFIGURE_ARGS+=	--disable-mmap
.endif

.if !defined(WITHOUT_PLASMAMULE)
CONFIGURE_ENV+=		ac_cv_path_KDE4_CONFIG=${KDE4_PREFIX}/bin/kde4-config
CONFIGURE_ARGS+=	--enable-plasmamule
USE_KDE4+=		kdelibs
QT_COMPONENTS+=		dbus gui moc_build
PLIST_SUB+=		PLASMAMULE=""
.else
CONFIGURE_ARGS+=	--disable-plasmamule
PLIST_SUB+=		PLASMAMULE="@comment "
.endif

.if !defined(WITHOUT_UPNP)
CONFIGURE_ARGS+=	--with-libupnp-prefix=${LOCALBASE}
LIB_DEPENDS+=		upnp.3:${PORTSDIR}/devel/upnp
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

.if !defined(WITHOUT_WXUNICODE)
WX_UNICODE=		yes
.endif

.if !defined(WITHOUT_XAS)
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
		${WRKSRC}/configure
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' ${WRKSRC}/docs/Makefile.in
.endif
.if !defined(WITHOUT_PLASMAMULE)
	${REINPLACE_CMD} -e 's|@prefix@|${KDE4_PREFIX}|' \
		-e 's|LDFLAGS =|& -L${KDE4_PREFIX}/lib |' \
		-e '/plasma.*feeder.*LDFLAGS/s/=/& -lQtDBus /' \
		-e 's/\(plasmamule_so_\)LDFLAGS/\1CXXFLAGS/' \
		${WRKSRC}/src/utils/plasmamule/Makefile.in
.endif

post-install:
.if !defined(WITHOUT_PLASMAMULE)
	-update-desktop-database ${KDE4_PREFIX}/share/applications
	-update-mime-database ${KDE4_PREFIX}/share/mime
.endif
	-update-desktop-database ${PREFIX}/share/applications

.include <bsd.port.post.mk>
