PORTNAME=	amule
PORTVERSION=	2.3.3
PORTREVISION=	16
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/aMule/${PORTVERSION}
DISTNAME=	aMule-${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	All-platform eMule p2p client
WWW=		https://www.amule.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/COPYING

LIB_DEPENDS=	libcryptopp.so:security/cryptopp

USES=		bison compiler:c++11-lang cpe desktop-file-utils gmake \
		localbase:ldflags perl5 pkgconfig shebangfix tar:xz
USE_PERL5=	build
USE_WX=		3.0
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-denoise-level=0

CONFIGURE_ENV=	LEX="${FLEX}" PKG_CONFIG="${PKG_CONFIG}" \
		docdir='$${prefix}/${DOCSDIR_REL}'

LDFLAGS+=	-lpthread

SHEBANG_FILES=	src/utils/scripts/*.pl src/utils/xas/*.pl src/libs/ec/*.pl

OPTIONS_DEFINE=	ALC ALCC AMULECMD AMULEDAEMON AMULEGUI BOOST CAS DEBUG \
		DOCS ED2K FILEVIEW MMAP MONOLITHIC NLS UPNP WEBSERVER \
		WXCAS XAS
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
WXCAS_DESC=		Compile aMule Statistics for GUI
XAS_DESC=		Install XChat2 plugin
OPTIONS_DEFAULT=	ALC ALCC AMULECMD AMULEDAEMON AMULEGUI BOOST CAS ED2K \
			FILEVIEW MONOLITHIC WEBSERVER WXCAS XAS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

ALC_CONFIGURE_ENABLE=	alc

ALCC_CONFIGURE_ENABLE=	alcc

AMULECMD_CONFIGURE_ENABLE=	amulecmd
AMULECMD_USES=		readline

AMULEDAEMON_CONFIGURE_ENABLE=	amule-daemon
AMULEDAEMON_USE=	RC_SUBR=amuled

AMULEGUI_CONFIGURE_ENABLE=	amule-gui

BOOST_CONFIGURE_WITH=	boost
BOOST_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
BOOST_USES=		autoreconf

CAS_CONFIGURE_ENABLE=	cas
CAS_LIB_DEPENDS=	libgd.so:graphics/gd

ED2K_CONFIGURE_ENABLE=	ed2k
ED2K_CONFLICTS=		ed2k-hash*

FILEVIEW_CONFIGURE_ENABLE=	fileview

MMAP_CONFIGURE_ENABLE=	mmap

MONOLITHIC_CONFIGURE_ENABLE=	monolithic

UPNP_LIB_DEPENDS=	libupnp.so:devel/upnp
UPNP_CONFIGURE_ENABLE=	upnp

WEBSERVER_CONFIGURE_ENABLE=	webserver
WEBSERVER_LIB_DEPENDS=	libpng.so:graphics/png
WEBSERVER_USES=		readline

# Build fails if only option selected
WXCAS_CONFIGURE_ENABLE=	wxcas

XAS_CONFIGURE_ENABLE=	xas
XAS_USE=	PERL5+=run

.include <bsd.port.options.mk>

# Fix segmentation fault, PR 266866
# see also 5a19c08: security/cryptopp: Update to 8.7.0
.if ${ARCH} == i386 || ${ARCH} == amd64
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

.if ${PORT_OPTIONS:MAMULEGUI} || ${PORT_OPTIONS:MMONOLITHIC}
PLIST_SUB+=	AMULESKIN=""
.else
PLIST_SUB+=	AMULESKIN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/test.*-print-file-name.*`/true/' \
		-e '/if.*test/s/==/=/' \
		${WRKSRC}/configure

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' \
		${WRKSRC}/docs/Makefile.in

post-install-FILEVIEW-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/utils/fileview/mulefileview ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.pre.mk>

# amule 2.3.3 does not work with C++17 which is the default since clang
# 16. Change the defaults and allow the `register' keyword to be used without
# triggering a compiler error to allow the build to work.
.if ${COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-register
.endif

.include <bsd.port.post.mk>
