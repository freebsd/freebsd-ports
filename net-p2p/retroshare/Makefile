# Created by: glocke@bsdstammtisch.at
# $FreeBSD$

PORTNAME=	retroshare
PORTVERSION=	0.5.5a
CATEGORIES=	net-p2p
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}/${BINARY}/${PORTVERSION}
DISTNAME=	${BINARY}-v${PORTVERSION}

MAINTAINER=	peter@netkey.at
COMMENT=	Private and secure decentralised communication platform

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libupnp.so:${PORTSDIR}/devel/upnp \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libassuan.so:${PORTSDIR}/security/libassuan \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libspeex.so:${PORTSDIR}/audio/speex \
		libxslt.so:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	pinentry-qt4:${PORTSDIR}/security/pinentry-qt4

USES=		qmake zip
USE_GNOME=	glib20
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_QT4=	corelib gui network xml script designer_build uic_build \
		moc_build rcc_build multimedia
BINARY=		RetroShare
MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

DESKTOP_ENTRIES="${BINARY}" "${COMMENT}" "${DATADIR}/retrosharelogo1.png" \
		"${BINARY}" "Network;FileTransfer;" true

USE_DOS2UNIX=	retroshare-gui/src/retroshare-gui.pro

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/libretroshare/src/libretroshare.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-gui/src/retroshare-gui.pro
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/retroshare-nogui/src/retroshare-nogui.pro
	@${REINPLACE_CMD} -e 's|/usr/local/share/retroshare|${DATADIR}|' \
		${WRKSRC}/libretroshare/src/rsserver/rsinit.cc
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/plugins/FeedReader/FeedReader.pro
	@${REINPLACE_CMD} -e 's|/usr/local/share/retroshare|${DATADIR}|' \
		${WRKSRC}/libretroshare/src/rsserver/rsinit.cc
	@${REINPLACE_CMD} -e 's|retroshare-nogui|#retroshare-nogui|' \
		${WRKSRC}/${BINARY}.pro
	@${REINPLACE_CMD} -e 's|/usr/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/libretroshare/src/rsserver/rsinit.cc

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-gui/src/${BINARY} \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/libbitdht/src/example/bdboot.txt \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/retroshare-gui/src/gui/images/retrosharelogo1.png \
		${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/retroshare
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/retroshare/extensions
	${INSTALL_LIB} ${WRKSRC}/plugins/LinksCloud/libLinksCloud.so.1.0.0 \
		${STAGEDIR}${PREFIX}/lib/retroshare/extensions/libLinksCloud.so.1
	${INSTALL_LIB} ${WRKSRC}/plugins/VOIP/libVOIP.so.1.0.0 \
		${STAGEDIR}${PREFIX}/lib/retroshare/extensions/libVOIP.so.1
	${INSTALL_LIB} ${WRKSRC}/plugins/FeedReader/libFeedReader.so.1.0.0 \
		${STAGEDIR}${PREFIX}/lib/retroshare/extensions/libFeedReader.so.1
	@cd ${STAGEDIR}${PREFIX}/lib/retroshare/extensions && \
		${LN} -s libLinksCloud.so.1 libLinksCloud.so && \
		${LN} -s libVOIP.so.1 libVOIP.so && \
		${LN} -s libFeedReader.so.1 libFeedReader.so

.include <bsd.port.mk>
