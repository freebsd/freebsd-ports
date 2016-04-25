# Created by: glocke@bsdstammtisch.at
# $FreeBSD$

PORTNAME=	retroshare
PORTVERSION=	0.5.5c
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${BINARY}/${PORTVERSION}
DISTNAME=	${PORTNAME}_${SRC_VERSION}-${SRC_REVISION}

MAINTAINER=	peter@netkey.at
COMMENT=	Private and secure decentralised communication platform

LICENSE=	GPLv2

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libupnp.so:devel/upnp \
		libgnome-keyring.so:security/libgnome-keyring \
		libspeex.so:audio/speex \
		libxslt.so:textproc/libxslt \
		libssh_threads.so:security/libssh

USES=		compiler:features dos2unix pkgconfig qmake
USE_GNOME=	glib20 libxml2 libxslt
USE_XORG=	x11 xscrnsaver
USE_QT4=	corelib gui network xml script designer_build uic_build \
		qmake_build moc_build rcc_build multimedia

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
