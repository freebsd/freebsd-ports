# Created by: glocke@bsdstammtisch.at
# $FreeBSD$

PORTNAME=	retroshare
PORTVERSION=	0.5.4b
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}/${BINARY}/${PORTVERSION}
DISTNAME=	${BINARY}-v${PORTVERSION}

MAINTAINER=	peter@netkey.at
COMMENT=	Private and secure decentralised communication platform

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		upnp:${PORTSDIR}/devel/upnp \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		assuan:${PORTSDIR}/security/libassuan \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		gpgme:${PORTSDIR}/security/gpgme \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb
RUN_DEPENDS+=	pinentry-qt4:${PORTSDIR}/security/pinentry-qt4

WRKSRC=		${WRKDIR}/trunk
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_XORG=	ice sm x11 xau xdmcp xext xrender
USE_QT4=	corelib gui network xml script designer_build uic_build \
		qmake_build moc_build rcc_build
HAS_CONFIGURE=	yes
BINARY=		RetroShare
BINARY_NOGUI=	retroshare-nogui
MAKE_JOBS_UNSAFE=yes

DESKTOP_ENTRIES="${BINARY}" "${COMMENT}" "" "${BINARY}" \
		"Network;FileTransfer;" true

OPTIONS_DEFINE=	NOGUI
NOGUI_DESC=		"Install retroshare-nogui binary"

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} ${BINARY}.pro

USE_DOS2UNIX=	retroshare-gui/src/retroshare-gui.pro \
	retroshare-nogui/src/retroshare-nogui.pro

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/libretroshare.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-gui/src/retroshare-gui.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-nogui/src/retroshare-nogui.pro
	@${REINPLACE_CMD} -e 's|/usr/local/share/retroshare|${DATADIR}|' \
		${WRKSRC}/libretroshare/src/rsserver/rsinit.cc
.if empty(PORT_OPTIONS:MNOGUI)
	@${REINPLACE_CMD} -e 's|retroshare-nogui|#retroshare-nogui|' \
		${WRKSRC}/${BINARY}.pro
	@${REINPLACE_CMD} -e 's|retroshare-gui.pro \\|retroshare-gui.pro|' \
		${WRKSRC}/${BINARY}.pro
.else
	@${REINPLACE_CMD} -e 's|retroshare-nogui.pro \\|retroshare-nogui.pro|' \
		${WRKSRC}/${BINARY}.pro
.endif
	@${REINPLACE_CMD} -e 's|plugins|#plugins|' ${WRKSRC}/${BINARY}.pro

pre-install:
.if empty(PORT_OPTIONS:MNOGUI)
PLIST_SUB+=	NOGUI="@comment "
.else
PLIST_SUB+=	NOGUI=""
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-gui/src/${BINARY} ${PREFIX}/bin
.if ${PORT_OPTIONS:MNOGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-nogui/src/${BINARY_NOGUI} ${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/libbitdht/src/example/bdboot.txt ${DATADIR}

.include <bsd.port.mk>
