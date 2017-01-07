# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qbittorrent
PORTVERSION=	3.3.10
PORTREVISION=	1
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@rawbw.com
COMMENT?=	Bittorrent client using Qt4/5 and libtorrent-rasterbar

LICENSE=	GPLv2

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lib execinfo pkgconfig tar:xz
QT4_USE=	QT4=corelib,network,xml,qmake_build,linguisttools_build,moc_build,rcc_build,uic_build
QT5_USE=	QT5=core,network,xml,qmake_build,buildtools_build,linguisttools_build
QT_NONSTANDARD=	yes
DESTDIRNAME=	INSTALL_ROOT
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS Changelog README.md

.if !defined(SLAVE_PORT) || ${SLAVE_PORT:tl} == "no"
WITH_GUI:=	yes
.else
WITH_GUI:=	no
.endif

OPTIONS_DEFINE=		DBUS DEBUG DOCS
OPTIONS_SINGLE=		QT
OPTIONS_SINGLE_QT=	QT4 QT5
OPTIONS_DEFAULT=	QT5
OPTION_QT=		${SELECTED_OPTIONS:MQT*}

DEBUG_CONFIGURE_ENABLE=	debug
DBUS_CONFIGURE_ENABLE=	qt-dbus
QT4_CONFIGURE_ON=	--with-qt4

.if ${WITH_GUI} == "yes"
LIB_DEPENDS+=		libGeoIP.so:net/GeoIP
USES+=			desktop-file-utils
QT4_USE+=		QT4=gui
QT5_USE+=		QT5=concurrent,gui,widgets GL=gl
OPTIONS_DEFAULT+=	DBUS
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
USE_${OPTION_QT}+=	dbus
.endif

CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

post-patch:
.if ${PORT_OPTIONS:MQT4}
	${REINPLACE_CMD} 's,^\$$QT_QMAKE,${LOCALBASE}/bin/qmake-qt4,' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.else
	${REINPLACE_CMD} 's,^\$$QT_QMAKE,${LOCALBASE}/lib/qt5/bin/qmake,' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-install:
.if ${WITH_GUI} == "yes"
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
.else
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent-nox
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent-nox.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
.endif
	@${RM} -r ${STAGEDIR}${PREFIX}/share/man

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
