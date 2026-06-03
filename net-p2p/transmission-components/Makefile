PORTNAME=	transmission
DISTVERSION=	4.1.1
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	mondo.debater_0q@icloud.com
COMMENT=	Transmission BitTorrent client
WWW=		https://www.transmissionbt.com

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=			daemon cli docs gtk qt utils web
FLAVOR?=			${FLAVORS:[1]}
${FLAVOR}_PKGNAMESUFFIX=	-${FLAVOR}

.if ${FLAVOR:Ndocs:Nweb}
BUILD_DEPENDS=	${LOCALBASE}/include/fast_float/fast_float.h:math/fast_float \
		${LOCALBASE}/include/fmt/format.h:devel/libfmt \
		${LOCALBASE}/include/math/wide_integer/uintwide_t.h:math/wide-integer \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson \
		${LOCALBASE}/include/small/map.hpp:devel/small \
		${LOCALBASE}/include/utf8cpp/utf8.h:devel/utf8cpp

LIB_DEPENDS=	libb64.so:converters/libb64 \
		libcrc32c.so:devel/crc32c \
		libcurl.so:ftp/curl \
		libdeflate.so:archivers/libdeflate \
		libdht.so:devel/jech-dht \
		libevent.so:devel/libevent \
		libminiupnpc.so:net/miniupnpc \
		libnatpmp.so:net/libnatpmp \
		libpsl.so:dns/libpsl \
		libutp.so:net-p2p/libutp

gtk_LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
			libharfbuzz.so:print/harfbuzz \
			libvulkan.so:graphics/vulkan-loader
.endif

USES=		${${FLAVOR}_USES} cpe tar:xz
CPE_VENDOR=	transmissionbt
CPE_PRODUCT=	transmission

.if ${FLAVOR:Ndocs:Nweb}
USE_GL=		${${FLAVOR}_USE_GL}
USE_GNOME=	${${FLAVOR}_USE_GNOME}
USE_QT=		${${FLAVOR}_USE_QT}

_all_USES=	cmake:testing compiler:c++20-lang iconv localbase pkgconfig ssl

cli_USES=	${_all_USES}

daemon_USES=	${_all_USES}

gtk_USES=	${_all_USES} desktop-file-utils gettext gnome
gtk_USE_GNOME=	gdkpixbuf glibmm gtkmm40

qt_USES=	${_all_USES} desktop-file-utils gl qmake:no_env qt:6
qt_USE_GL=	opengl
qt_USE_QT=	base svg tools translations:build

utils_USES=	${_all_USES}

.if ${FLAVOR:Mdaemon}
USE_RC_SUBR=	${PORTNAME}
.endif

CMAKE_ARGS=	${${FLAVOR}_CMAKE_ARGS} -DCMAKE_CXX_STANDARD=20 \
		-DWideInteger_DIR=${PREFIX}/lib/cmake/wide-integer
CMAKE_ON=	${${FLAVOR}_CMAKE_ON} USE_SYSTEM_DEFAULT
CMAKE_OFF=	${${FLAVOR}_CMAKE_OFF} ENABLE_MAC RUN_CLANG_TIDY WITH_SYSTEMD

cli_CMAKE_ON=		ENABLE_CLI
cli_CMAKE_OFF=		ENABLE_DAEMON ENABLE_GTK ENABLE_QT ENABLE_UTILS INSTALL_WEB

daemon_CMAKE_ON=	ENABLE_DAEMON
daemon_CMAKE_OFF=	ENABLE_CLI ENABLE_GTK ENABLE_QT ENABLE_UTILS INSTALL_WEB

gtk_CMAKE_ARGS=		-DUSE_GTK_VERSION=4
gtk_CMAKE_ON=		ENABLE_GTK GTK_IS_REQUIRED
gtk_CMAKE_OFF=		ENABLE_CLI ENABLE_DAEMON ENABLE_UTILS INSTALL_WEB

qt_CMAKE_ARGS=		-DUSE_QT_VERSION=6
qt_CMAKE_ON=		ENABLE_QT QT_IS_REQUIRED
qt_CMAKE_OFF=		ENABLE_CLI ENABLE_DAEMON ENABLE_UTILS INSTALL_WEB

utils_CMAKE_ON=		ENABLE_UTILS
utils_CMAKE_OFF=	ENABLE_CLI ENABLE_DAEMON ENABLE_GTK ENABLE_QT INSTALL_WEB
.endif

EXTRACT_AFTER_ARGS=	${B64 CRC32C FastFloat DEFLATE DHT Fmt MINIUPNPC \
			NATPMP PSL Small UtfCpp UTP WideInteger \
			:L:C|^(.*)|--exclude cmake/Find\1.cmake|} \
			--exclude news/news-[0-3]* \
			--exclude news/news-*beta* \
			${dht fast_float fmt libb64 libdeflate libevent \
			libnatpmp libpsl libutp miniupnpc rapidjson small \
			utfcpp wide-integer:L:S|^|--exclude third-party/|} \
			--no-same-owner --no-same-permissions

.if ${FLAVOR:Mdocs} || ${FLAVOR:Mweb}
NO_ARCH=	yes
NO_BUILD=	yes
.endif

.if ${FLAVOR:Ndocs}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
.endif

DESCR=		${PKGDIR}/pkg-descr.${FLAVOR}
PLIST=		${PKGDIR}/pkg-plist.${FLAVOR}

.if ${FLAVOR:Ndocs:Nweb}
OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_FILE=		${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options
OPTIONS_SUB=		yes
NLS_USES=		gettext-runtime
NLS_CMAKE_BOOL=		ENABLE_NLS
.endif

.if ${FLAVOR:Mdocs}
do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} news ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${AUTHORS COPYING README.md docs/rpc-spec.md \
		extras/send-email-when-torrent-done.sh:L:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}
.endif

.if ${FLAVOR:Mweb}
do-install:
	(cd ${WRKSRC}/web && ${COPYTREE_SHARE} public_html ${STAGEDIR}${DATADIR})
.endif

post-install:
.if ${FLAVOR:Mdaemon}
	${MKDIR} ${STAGEDIR}${ETCDIR}/home
.endif
.if ${FLAVOR:Mgtk} || ${FLAVOR:Mqt}
	${RM} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/transmission-devel.svg
.endif

.include <bsd.port.mk>
