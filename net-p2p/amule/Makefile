# New ports collection makefile for:	amule
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	amule
PORTVERSION=	2.3.1
PORTREVISION=	4
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/aMule/${PORTVERSION}
DISTNAME=	aMule-${PORTVERSION}

MAINTAINER=	barbara.xxx1975@libero.it
COMMENT=	The all-platform eMule p2p client

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LICENSE_FILE_GPLv2=${WRKSRC}/docs/COPYING

CONFLICTS=	amule-devel-[0-9]*

BUILD_DEPENDS=	${FLEX}:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp

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

OPTIONS=	ALC "Compile aMule Link Creator for GUI" on \
		ALCC "Compile aMule Link Creator for console" on \
		AMULECMD "Compile aMule command line client" on \
		AMULEDAEMON "Compile aMule daemon version" on \
		AMULEGUI "Compile aMule remote GUI" on \
		CAS "Compile aMule Statistics for console" on \
		ED2K "Compile aMule ed2k links handler" on \
		FILEVIEW "Compile file viewer for console (EXPERIMENTAL)" on \
		GEOIP "Enable GeoIP IP2Country support" off \
		MMAP "Enable using mapped memory" off \
		MONOLITHIC "Compile monolithic aMule" on \
		PLASMAMULE "Compile aMule plasma applet and engine" off \
		UPNP "Enable Universal Plug and Play support" off \
		WEBSERVER "Compile aMule WebServer" on \
		WXCAS "Compile aMule Statistics for GUI" on \
		WXUNICODE "Enable Unicode support" on \
		XAS "Install XChat2 plugin" on

PORTDOCS=	ABOUT-NLS Changelog EC_Protocol.txt INSTALL README TODO \
		amulesig.txt license.txt

FLEX?=		${LOCALBASE}/bin/flex
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config

.include <bsd.port.options.mk>

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
USE_RC_SUBR=		amuled
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

.if !defined(WITHOUT_FILEVIEW)
CONFIGURE_ARGS+=	--enable-fileview
PLIST_SUB+=		FILEVIEW=""
.else
CONFIGURE_ARGS+=	--disable-fileview
PLIST_SUB+=		FILEVIEW="@comment "
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

.if !defined(WITHOUT_MONOLITHIC)
CONFIGURE_ARGS+=	--enable-monolithic
PLIST_SUB+=		MONOLITHIC=""
.else
CONFIGURE_ARGS+=	--disable-monolithic
PLIST_SUB+=		MONOLITHIC="@comment "
.endif

.if !defined(WITHOUT_PLASMAMULE)
CONFIGURE_ENV+=		ac_cv_path_KDE4_CONFIG=${KDE4_PREFIX}/bin/kde4-config \
			KBUILDSYCOCA=${KDE4_PREFIX}/bin/kbuildsycoca4 \
			UPDATE_MIME_DATABASE=/usr/bin/true
CONFIGURE_ARGS+=	--enable-plasmamule
USE_KDE4=		kdelibs
USE_QT4+=		dbus gui moc_build
PLIST_SUB+=		PLASMAMULE=""
.else
CONFIGURE_ARGS+=	--disable-plasmamule
PLIST_SUB+=		PLASMAMULE="@comment "
.endif

.if !defined(WITHOUT_UPNP)
LIB_DEPENDS+=		upnp.9:${PORTSDIR}/devel/upnp
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
		-e '/if.*test/s/==/=/' \
		${WRKSRC}/configure
	${FIND} ${WRKSRC} -name \*.pl -exec ${REINPLACE_CMD} \
		's|/usr/bin/perl|${PERL}|' {} +
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' \
		${WRKSRC}/docs/Makefile.in
.endif
.if !defined(WITHOUT_PLASMAMULE)
	${REINPLACE_CMD} -e 's|@prefix@|${KDE4_PREFIX}|' \
		-e 's|LDFLAGS =|& -L${KDE4_PREFIX}/lib |' \
		${WRKSRC}/src/utils/plasmamule/Makefile.in
.endif

post-install:
.if !defined(WITHOUT_FILEVIEW)
	${INSTALL_PROGRAM} ${WRKSRC}/src/utils/fileview/mulefileview ${PREFIX}/bin
.endif
.if exists(${LOCALBASE}/bin/update-desktop-database)
. if !defined(WITHOUT_PLASMAMULE)
	-update-desktop-database ${KDE4_PREFIX}/share/applications
.  if exists(${LOCALBASE}/bin/update-mime-database)
	-update-mime-database ${KDE4_PREFIX}/share/mime
.  endif
. endif
	-update-desktop-database ${PREFIX}/share/applications
.endif

.include <bsd.port.mk>
