# Created by: Ganael LAPLANCHE <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	amule
PORTVERSION=	10990
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://amule.sourceforge.net/tarballs/
PKGNAMESUFFIX=	-devel
DISTNAME=	aMule-SVN-r${PORTVERSION}

MAINTAINER=	bar@FreeBSD.org
COMMENT=	All-platform eMule p2p client

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libcryptopp.so:security/cryptopp

CONFLICTS=	amule-[0-9]*

USES=		bison desktop-file-utils gmake perl5 pkgconfig shebangfix \
		tar:bzip2
USE_PERL5=	build
USE_WX=		2.8
WX_CONF_ARGS=	absolute

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-denoise-level=0

CONFIGURE_ENV=	LEX="${FLEX}" PKG_CONFIG="${PKG_CONFIG}" \
		docdir='$${prefix}/${DOCSDIR_REL}'

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_DEFINE=	ALC ALCC AMULECMD AMULEDAEMON AMULEGUI CAS DEBUG DOCS ED2K \
	FILEVIEW GEOIP MMAP MONOLITHIC NLS OPTIMIZED_CFLAGS PLASMAMULE UPNP \
	WEBSERVER WXCAS XAS
ALC_DESC=		Compile aMule Link Creator for GUI
ALCC_DESC=		Compile aMule Link Creator for console
AMULECMD_DESC=		Compile aMule command line client
AMULEDAEMON_DESC=	Compile aMule daemon version
AMULEGUI_DESC=		Compile aMule remote GUI
CAS_DESC=		Compile aMule Statistics for console
ED2K_DESC=		Compile aMule ed2k links handler
FILEVIEW_DESC=		Compile file viewer for console (EXPERIMENTAL)
MMAP_DESC=		Use mapped memory
MONOLITHIC_DESC=	Compile monolithic aMule
PLASMAMULE_DESC=	Compile aMule plasma applet and engine
WXCAS_DESC=		Compile aMule Statistics for GUI
XAS_DESC=		Install XChat2 plugin
OPTIONS_DEFAULT=ALC ALCC AMULECMD AMULEDAEMON AMULEGUI CAS ED2K \
	FILEVIEW MONOLITHIC WEBSERVER WXCAS XAS

OPTIONS_SUB=	yes

SHEBANG_FILES=	src/utils/scripts/*.pl src/utils/xas/*.pl src/libs/ec/*.pl

LICENSE_FILE_GPLv2=${WRKSRC}/docs/COPYING

DEBUG_CONFIGURE_ON=	--enable-debug

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

ALC_CONFIGURE_ON=	--enable-alc

ALCC_CONFIGURE_ON=	--enable-alcc

AMULECMD_CONFIGURE_ON=	--enable-amulecmd

AMULEDAEMON_CONFIGURE_ON=	--enable-amule-daemon
AMULEDAEMON_USE=	RC_SUBR=amuled

AMULEGUI_CONFIGURE_ON=	--enable-amule-gui

CAS_CONFIGURE_ON=	--enable-cas
CAS_LIB_DEPENDS=	libgd.so:graphics/gd

ED2K_CONFIGURE_OFF=	--disable-ed2k

FILEVIEW_CONFIGURE_ON=	--enable-fileview

GEOIP_CONFIGURE_ON=	--enable-geoip
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP

MMAP_CONFIGURE_ON=	--enable-mmap

MONOLITHIC_CONFIGURE_OFF=	--disable-monolithic

PLASMAMULE_CONFIGURE_ON=	--enable-plasmamule
PLASMAMULE_USES=	kde:4
PLASMAMULE_USE=	KDE=kdelibs QT4=dbus,gui,moc_build
PLASMAMULE_CONFIGURE_ENV= \
			ac_cv_path_KDE4_CONFIG=${KDE_PREFIX}/bin/kde4-config \
			KBUILDSYCOCA=${KDE_PREFIX}/bin/kbuildsycoca4 \
			UPDATE_MIME_DATABASE=/usr/bin/true

UPNP_LIB_DEPENDS=	libupnp.so:devel/upnp
UPNP_CONFIGURE_OFF=	--disable-upnp

WEBSERVER_CONFIGURE_ON=	--enable-webserver
WEBSERVER_LIB_DEPENDS=	libpng.so:graphics/png

WXCAS_CONFIGURE_ON=	--enable-wxcas

XAS_CONFIGURE_ON=	--enable-xas
XAS_USE=	PERL5+=run

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" && ( ${OSVERSION} >= 1000024 || ${CXX:T} == "clang++" )
CPPFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

.if ${PORT_OPTIONS:MED2K}
CONFLICTS+=		ed2k-hash*
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CONFIGURE_ARGS+=	--enable-optimize
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's/test.*-print-file-name.*`/true/' \
		-e '/if.*test/s/==/=/' \
		${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' \
		${WRKSRC}/docs/Makefile.in
.endif
.if ${PORT_OPTIONS:MPLASMAMULE}
	${REINPLACE_CMD} -e 's|@prefix@|${KDE_PREFIX}|' \
		-e 's|LDFLAGS =|& -L${KDE_PREFIX}/lib |' \
		${WRKSRC}/src/utils/plasmamule/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MFILEVIEW}
	${INSTALL_PROGRAM} ${WRKSRC}/src/utils/fileview/mulefileview ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
