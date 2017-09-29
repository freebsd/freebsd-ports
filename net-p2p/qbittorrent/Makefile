# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qbittorrent
PORTVERSION=	3.3.15
PORTREVISION=	3
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@rawbw.com
COMMENT?=	Bittorrent client using Qt4/5 and libtorrent-rasterbar

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lib pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_QT5=	core network xml qmake_build buildtools_build linguisttools_build
QT_NONSTANDARD=	yes
DESTDIRNAME=	INSTALL_ROOT
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS Changelog README.md

.if !defined(SLAVE_PORT) || ${SLAVE_PORT:tl} == "no"
WITH_GUI:=	yes
.else
WITH_GUI:=	no
SUFFIX:=	-nox
.endif

OPTIONS_DEFINE=		DBUS DEBUG DOCS

DEBUG_CONFIGURE_ENABLE=	debug
DBUS_CONFIGURE_ENABLE=	qt-dbus
DBUS_USE=		qt5=dbus

.if ${WITH_GUI} == "yes"
LIB_DEPENDS+=		libGeoIP.so:net/GeoIP
USES+=			desktop-file-utils
USE_QT5+=		concurrent gui widgets
USE_GL+=		gl
OPTIONS_DEFAULT+=	DBUS
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

post-patch:
	@${REINPLACE_CMD} \
		-e 's/#ifdef Q_OS_MAC/#if defined(Q_OS_MAC) || (defined(__FreeBSD__) \&\& __FreeBSD_version < 1003506)/' \
		${WRKSRC}/src/base/utils/string.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent${SUFFIX}
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent${SUFFIX}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	${RM} -r ${STAGEDIR}${PREFIX}/share/man

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
