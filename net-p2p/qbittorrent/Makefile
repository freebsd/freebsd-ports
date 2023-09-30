PORTNAME=	qbittorrent
DISTVERSION=	4.6.2
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bittorrent client using Qt6 and libtorrent-rasterbar
WWW=		https://www.qbittorrent.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED # error: "Boost.Stacktrace requires `_Unwind_Backtrace` function. Define `_GNU_SOURCE` macro or `BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED` if _Unwind_Backtrace is available without `_GNU_SOURCE`."

FLAVORS=	default nox
FLAVOR?=	${FLAVORS:[1]}
nox_PKGNAMESUFFIX=	-nox
nox_PLIST=		${MASTERDIR}/pkg-plist-nox

USES=			compiler:c++14-lang cpe pkgconfig cmake localbase qt:6 ssl tar:xz
USE_QT=			base translations
USE_CXXSTD=		c++17 # prevent boost-related SEGV, see bug#264278

USE_GITHUB=		nodefault
GH_ACCOUNT=		qBittorrent
GH_PROJECT=		qBittorrent

CMAKE_ON=		QT6

.if ${FLAVOR} == default
USES+=			desktop-file-utils gl
USE_QT+=		svg
USE_GL=			gl
CMAKE_OFF=		WEBUI
.endif

.if ${FLAVOR} == nox
COMMENT+=		(web UI version)
CMAKE_OFF=		GUI
USERS=			qbittorrent
GROUPS=			qbittorrent
USE_RC_SUBR=		qbittorrent
SUB_LIST=		USER=${USERS} GROUP=${GROUPS}
PLIST_SUB=		USER=${USERS} GROUP=${GROUPS}
OPTIONS_EXCLUDE=	DBUS
.endif

OPTIONS_DEFINE=			DBUS PYTHON DEBUG
OPTIONS_RADIO=			LIBTORRENT
OPTIONS_RADIO_LIBTORRENT=	LIBTORRENT1 LIBTORRENT2
OPTIONS_DEFAULT=		DBUS PYTHON LIBTORRENT1

LIBTORRENT_DESC=	libtorrent version number to use
LIBTORRENT1_DESC=	Version 1.x (default)
LIBTORRENT2_DESC=	Version 2.x (experimental)

DEBUG_CMAKE_BOOL=	debug
DBUS_CMAKE_BOOL=	DBUS

LIBTORRENT1_BUILD_DEPENDS=	libtorrent-rasterbar>0:net-p2p/libtorrent-rasterbar
LIBTORRENT1_RUN_DEPENDS=	libtorrent-rasterbar>0:net-p2p/libtorrent-rasterbar
LIBTORRENT2_BUILD_DEPENDS=	libtorrent-rasterbar2>0:net-p2p/libtorrent-rasterbar2
LIBTORRENT2_RUN_DEPENDS=	libtorrent-rasterbar2>0:net-p2p/libtorrent-rasterbar2
LIBTORRENT2_EXTRA_PATCHES=	${FILESDIR}/extrapatch-libtorrent-rasterbar2-settings

PYTHON_DESC=		Install Python to support some plugin functionality
PYTHON_USES=		python:run

post-patch-PYTHON-on:
	@${REINPLACE_CMD} \
		-e 's|"python3"|"${PYTHON_CMD}"|' \
		${WRKSRC}/src/base/utils/foreignapps.cpp

post-install:
.if ${FLAVOR} == nox
	@${MKDIR} ${STAGEDIR}/var/db/qbittorrent/conf ${STAGEDIR}/var/db/qbittorrent/Downloads
.endif

.include <bsd.port.mk>
