# Created by: Ganael LAPLANCHE <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	amule
PORTVERSION=	2.3.2
PORTREVISION=	9
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/aMule/${PORTVERSION}
DISTNAME=	aMule-${PORTVERSION}

MAINTAINER=	bar@FreeBSD.org
COMMENT=	All-platform eMule p2p client

LICENSE=	GPLv2+
LICENSE_FILE_GPLv2+ =	${WRKSRC}/docs/COPYING

LIB_DEPENDS=	libcryptopp.so:security/cryptopp

CONFLICTS=	amule-devel-[0-9]*

USES=		bison compiler:c++11-lang desktop-file-utils gmake \
		localbase:ldflags perl5 pkgconfig shebangfix tar:xz
USE_PERL5=	build
USE_WX=		2.8
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-denoise-level=0

CONFIGURE_ENV=	LEX="${FLEX}" PKG_CONFIG="${PKG_CONFIG}" \
		docdir='$${prefix}/${DOCSDIR_REL}'

CXXFLAGS+=	`pkgconf --cflags-only-other libcryptopp`
LDFLAGS+=	-lpthread

SHEBANG_FILES=	src/utils/scripts/*.pl src/utils/xas/*.pl src/libs/ec/*.pl

OPTIONS_DEFINE=	ALC ALCC AMULECMD AMULEDAEMON AMULEGUI CAS DEBUG DOCS ED2K \
	FILEVIEW MMAP MONOLITHIC NLS UPNP \
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
WXCAS_DESC=		Compile aMule Statistics for GUI
XAS_DESC=		Install XChat2 plugin
OPTIONS_DEFAULT=ALC ALCC AMULECMD AMULEDAEMON AMULEGUI CAS ED2K \
	FILEVIEW MONOLITHIC WEBSERVER WXCAS XAS

OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--enable-debug

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

ALC_CONFIGURE_ON=	--enable-alc

ALCC_CONFIGURE_ON=	--enable-alcc

AMULECMD_CONFIGURE_ON=	--enable-amulecmd
AMULECMD_USES=		readline

AMULEDAEMON_CONFIGURE_ON=	--enable-amule-daemon
AMULEDAEMON_USE=	RC_SUBR=amuled

AMULEGUI_CONFIGURE_ON=	--enable-amule-gui

CAS_CONFIGURE_ON=	--enable-cas
CAS_LIB_DEPENDS=	libgd.so:graphics/gd

ED2K_CONFIGURE_OFF=	--disable-ed2k
ED2K_CONFLICTS=		ed2k-hash*

FILEVIEW_CONFIGURE_ON=	--enable-fileview

MMAP_CONFIGURE_ON=	--enable-mmap

MONOLITHIC_CONFIGURE_OFF=	--disable-monolithic

UPNP_LIB_DEPENDS=	libupnp.so:devel/upnp
UPNP_CONFIGURE_OFF=	--disable-upnp

WEBSERVER_CONFIGURE_ON=	--enable-webserver
WEBSERVER_USES=		readline

WXCAS_CONFIGURE_ON=	--enable-wxcas

XAS_CONFIGURE_ON=	--enable-xas
XAS_USE=	PERL5+=run

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/test.*-print-file-name.*`/true/' \
		-e '/if.*test/s/==/=/' \
		${WRKSRC}/configure

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's/install-data-am:.*/install-data-am:/' \
		${WRKSRC}/docs/Makefile.in

post-install-FILEVIEW-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/utils/fileview/mulefileview ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
