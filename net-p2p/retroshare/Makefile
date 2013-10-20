# Created by: glocke@bsdstammtisch.at
# $FreeBSD$

PORTNAME=	retroshare
PORTVERSION=	0.5.4d
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
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS+=	pinentry-qt4:${PORTSDIR}/security/pinentry-qt4

WRKSRC=		${WRKDIR}/trunk
USES=		gettext iconv
USE_GNOME=	glib20
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_QT4=	corelib gui network xml script designer_build uic_build \
		qmake_build moc_build rcc_build
HAS_CONFIGURE=	yes
BINARY=		RetroShare
BINARY_NOGUI=	retroshare-nogui
MAKE_JOBS_UNSAFE=yes

DESKTOP_ENTRIES="${BINARY}" "${COMMENT}" "" "${BINARY}" \
		"Network;FileTransfer;" true

OPTIONS_DEFINE=	NOGUI PLUGINS
OPTIONS_DEFAULT=	PLUGINS
NOGUI_DESC=		Install retroshare-nogui (CLI binary)
PLUGINS_DESC=	Install plugins (LinksCloud, VoIP)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLUGINS}
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
USE_QT4+=	multimedia
USE_LDCONFIG=	yes
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} ${BINARY}.pro

USE_DOS2UNIX=	retroshare-gui/src/retroshare-gui.pro \
		retroshare-nogui/src/retroshare-nogui.pro \
		retroshare-gui/src/gui/common/GroupTreeWidget.cpp

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
.if empty(PORT_OPTIONS:MPLUGINS)
	@${REINPLACE_CMD} -e 's|retroshare-gui.pro \\|retroshare-gui.pro|' \
		${WRKSRC}/${BINARY}.pro
.endif
.else
.if empty(PORT_OPTIONS:MPLUGINS)
	@${REINPLACE_CMD} -e 's|retroshare-nogui.pro \\|retroshare-nogui.pro|' \
		${WRKSRC}/${BINARY}.pro
.endif
.endif
.if empty(PORT_OPTIONS:MPLUGINS)
	@${REINPLACE_CMD} -e 's|plugins|#plugins|' ${WRKSRC}/${BINARY}.pro
.else
	@${REINPLACE_CMD} -e 's|/usr/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/libretroshare/src/rsserver/rsinit.cc
.endif

pre-install:
.if empty(PORT_OPTIONS:MNOGUI)
PLIST_SUB+=	NOGUI="@comment "
.else
PLIST_SUB+=	NOGUI=""
.endif
.if empty(PORT_OPTIONS:MPLUGINS)
PLIST_SUB+=	PLUGINS="@comment "
.else
PLIST_SUB+=	PLUGINS=""
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-gui/src/${BINARY} ${PREFIX}/bin
.if ${PORT_OPTIONS:MNOGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-nogui/src/${BINARY_NOGUI} ${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/libbitdht/src/example/bdboot.txt ${DATADIR}
.if ${PORT_OPTIONS:MPLUGINS}
	${MKDIR} ${PREFIX}/lib/retroshare
	${MKDIR} ${PREFIX}/lib/retroshare/extensions
	${INSTALL_LIB} ${WRKSRC}/plugins/LinksCloud/libLinksCloud.so.1.0.0 \
		${PREFIX}/lib/retroshare/extensions/libLinksCloud.so.1
	${INSTALL_LIB} ${WRKSRC}/plugins/VOIP/libVOIP.so.1.0.0 \
		${PREFIX}/lib/retroshare/extensions/libVOIP.so.1
	@cd ${PREFIX}/lib/retroshare/extensions && \
		${LN} -s libLinksCloud.so.1 libLinksCloud.so && \
		${LN} -s libVOIP.so.1 libVOIP.so
.endif

.include <bsd.port.mk>
