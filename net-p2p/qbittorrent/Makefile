# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qbittorrent
DISTVERSION=	4.1.9.1
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bittorrent client using Qt5 and libtorrent-rasterbar

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		libboost_system.so:devel/boost-libs

FLAVORS=	default nox
FLAVOR?=	${FLAVORS:[1]}
nox_PKGNAMESUFFIX=	-nox
nox_PLIST=		${MASTERDIR}/pkg-plist-nox

USES=			compiler:c++11-lib pkgconfig qmake:no_env qt:5 tar:xz
GNU_CONFIGURE=		yes
USE_QT=			core network xml buildtools_build linguisttools_build qmake_build
CONFIGURE_ARGS=		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
DESTDIRNAME=		INSTALL_ROOT

.if ${FLAVOR} == default
USES+=			desktop-file-utils gl
USE_QT+=		concurrent gui svg widgets
USE_GL=			gl
.endif

.if ${FLAVOR} == nox
SUFFIX=			-nox
COMMENT+=		(web UI version)
CONFIGURE_ARGS+=	--disable-gui
USERS=			qbittorrent
GROUPS=			qbittorrent
USE_RC_SUBR=		qbittorrent
SUB_LIST=		USER=${USERS} GROUP=${GROUPS}
PLIST_SUB=		USER=${USERS} GROUP=${GROUPS}
.endif

OPTIONS_DEFINE=		DBUS DEBUG
OPTIONS_DEFAULT=	DBUS

DEBUG_CONFIGURE_ENABLE=	debug
DBUS_CONFIGURE_ENABLE=	qt-dbus
DBUS_USE=		qt=dbus

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbittorrent${SUFFIX}
	${INSTALL_MAN} ${WRKSRC}/doc/qbittorrent${SUFFIX}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${RM} -r ${STAGEDIR}${PREFIX}/share/man
.if ${FLAVOR} == nox
	@${MKDIR} ${STAGEDIR}/var/db/qbittorrent/conf ${STAGEDIR}/var/db/qbittorrent/Downloads
.endif

.include <bsd.port.mk>
