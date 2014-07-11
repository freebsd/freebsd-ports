# Created by: glocke@bsdstammtisch.at
# $FreeBSD$

PORTNAME=	retroshare
PORTVERSION=	0.5.5c
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}/${BINARY}/${PORTVERSION}
DISTNAME=	${PORTNAME}_${SRC_VERSION}-${SRC_REVISION}

MAINTAINER=	peter@netkey.at
COMMENT=	Private and secure decentralised communication platform

LICENSE=	GPLv2

BUILD_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf \
		pkg-config:${PORTSDIR}/devel/pkgconf
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
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libssh_threads.so:${PORTSDIR}/security/libssh
RUN_DEPENDS=	pinentry-qt4:${PORTSDIR}/security/pinentry-qt4

USES=		compiler:features dos2unix qmake
USE_GNOME=	glib20
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_QT4=	corelib gui network xml script designer_build uic_build \
		qmake_build moc_build rcc_build multimedia
HAS_CONFIGURE=	yes

BINARY=		RetroShare
SRC_REVISION=	0.7068
SRC_VERSION=	0.5.5
WRKSRC=		${WRKDIR}/${PORTNAME}-${SRC_VERSION}/src

MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

DESKTOP_ENTRIES="${BINARY}" "${COMMENT}" "${DATADIR}/retrosharelogo1.png" \
		"${BINARY}" "Network;FileTransfer;" true

DOS2UNIX_FILES=	retroshare-gui/src/retroshare-gui.pro \
	retroshare-nogui/src/retroshare-nogui.pro \
	retroshare-gui/src/gui/RetroShareLink.h \
	retroshare-gui/src/gui/common/GroupTreeWidget.cpp

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_FEATURES:Mlibc++}
	@${REINPLACE_CMD} -e 's|std::tr1::|std::|' \
		${WRKSRC}/libretroshare/src/dbase/findex.[ch]*
.endif
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
	@${REINPLACE_CMD} -e 's|/usr/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/libretroshare/src/rsserver/rsinit.cc

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-gui/src/${BINARY} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/retroshare-nogui/src/retroshare-nogui \
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

.include <bsd.port.post.mk>
