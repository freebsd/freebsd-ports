PORTNAME=	transmission
DISTVERSION=	4.0.6
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	mondo.debater_0q@icloud.com
COMMENT=	Transmission BitTorrent client
WWW=		https://www.transmissionbt.com

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fast_float/fast_float.h:math/fast_float \
		${LOCALBASE}/include/fmt/format.h:devel/libfmt \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson \
		${LOCALBASE}/include/utf8cpp/utf8.h:devel/utf8cpp

LIB_DEPENDS=	libb64.so:converters/libb64 \
		libcurl.so:ftp/curl \
		libdeflate.so:archivers/libdeflate \
		libdht.so:devel/jech-dht \
		libevent.so:devel/libevent \
		libminiupnpc.so:net/miniupnpc \
		libnatpmp.so:net/libnatpmp \
		libpsl.so:dns/libpsl \
		libutp.so:net-p2p/libutp

FLAVORS=			cli docs daemon gtk qt utils web
FLAVOR?=			${FLAVORS:[1]}
.for flavor in ${FLAVORS}
${flavor}_PKGNAMESUFFIX=	-${flavor}
.endfor

DESCR=		${PKGDIR}/pkg-descr.${FLAVOR}

.if ${FLAVOR} == docs
NO_BUILD=	yes
LIB_DEPENDS=
.endif

gtk_LIB_DEPENDS=	libayatana-appindicator3.so:devel/libayatana-appindicator \
			libharfbuzz.so:print/harfbuzz

USES=		cmake cpe iconv localbase pkgconfig ssl tar:xz

CPE_VENDOR=	transmissionbt
CPE_PRODUCT=	transmission

EXTRACT_AFTER_ARGS=	--exclude third-party/dht \
			--exclude third-party/fast_float \
			--exclude third-party/fmt \
			--exclude third-party/libb64 \
			--exclude third-party/libdeflate \
			--exclude third-party/libevent \
			--exclude third-party/libnatpmp \
			--exclude third-party/libpsl \
			--exclude third-party/libutp \
			--exclude third-party/miniupnpc \
			--exclude third-party/rapidjson \
			--exclude third-party/utfcpp

.if ${FLAVOR} == gtk
USES+=		desktop-file-utils gettext-runtime gettext-tools gnome
USE_GNOME=	gdkpixbuf glibmm gtkmm30
.endif

.if ${FLAVOR} == qt
USES+=		desktop-file-utils qmake:no_env qt:5
USE_QT=		core dbus gui network svg widgets buildtools:build \
		linguisttools:build
.endif

.if ${FLAVOR} == daemon
USE_RC_SUBR=	transmission
.endif

.if ${FLAVOR} == docs
USES=		cpe tar:xz
.endif

.if ${FLAVOR} == web
USES=		cpe tar:xz
NO_ARCH=	yes
NO_BUILD=	yes
.endif

CMAKE_ON=	USE_SYSTEM_B64 USE_SYSTEM_DEFLATE USE_SYSTEM_DHT \
		USE_SYSTEM_EVENT2 USE_SYSTEM_MINIUPNPC USE_SYSTEM_NATPMP \
		USE_SYSTEM_PSL USE_SYSTEM_UTP
CMAKE_OFF=	ENABLE_MAC REBUILD_WEB WITH_SYSTEMD

.if ${FLAVOR:Ndocs}
USERS=		transmission
GROUPS=		transmission
.endif

PLIST=		${PKGDIR}/pkg-plist.${FLAVOR}

.if ${FLAVOR} == cli
CMAKE_ON+=	ENABLE_CLI
CMAKE_OFF+=	ENABLE_DAEMON ENABLE_GTK ENABLE_QT ENABLE_UTILS INSTALL_WEB
.endif

.if ${FLAVOR} == daemon
CMAKE_ON+=	ENABLE_DAEMON
CMAKE_OFF+=	ENABLE_CLI ENABLE_GTK ENABLE_QT ENABLE_UTILS INSTALL_WEB
.endif

.if ${FLAVOR} == gtk
CMAKE_ARGS+=	-DUSE_GTK_VERSION=3
CMAKE_ON+=	ENABLE_GTK GTK_IS_REQUIRED
CMAKE_OFF+=	ENABLE_CLI ENABLE_DAEMON ENABLE_UTILS INSTALL_WEB
.endif

.if ${FLAVOR} == qt
CMAKE_ARGS+=	-DUSE_QT_VERSION=5
CMAKE_ON+=	ENABLE_QT QT_IS_REQUIRED
CMAKE_OFF+=	ENABLE_CLI ENABLE_DAEMON ENABLE_UTILS INSTALL_WEB
.endif

.if ${FLAVOR} == utils
CMAKE_ON+=	ENABLE_UTILS
CMAKE_OFF+=	ENABLE_CLI ENABLE_DAEMON ENABLE_GTK ENABLE_QT ENABLE_TESTS \
		ENABLE_WERROR INSTALL_WEB
.endif

OPTIONS_FILE=	${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options

.if ${FLAVOR:Mdocs}
OPTIONS_DEFINE=
.endif

.if ${FLAVOR:Mweb}
OPTIONS_DEFINE=
.endif

.if ${FLAVOR:Nweb} && ${FLAVOR:Ndocs}
OPTIONS_DEFINE=		NLS TESTS
OPTIONS_DEFAULT=	NLS
.endif

OPTIONS_SUB=	yes

daemon_DESC=	Build daemon
docs_DESC=	Install documentation
gtk_DESC=	Build GTK+ client
qt_DESC=	Build QT client
TESTS_DESC=	Build & run unit tests
utils_DESC=	Build utilities (create, edit, remote, show)
cli_DESC=	Build command-line client (deprecated)
web_DESC=	Install web interface

NLS_USES=	gettext-runtime:lib
NLS_CMAKE_BOOL=	ENABLE_NLS

TESTS_CMAKE_BOOL=	ENABLE_TESTS

UTILS_CMAKE_BOOL=	ENABLE_UTILS

WEB_CMAKE_BOOL=	INSTALL_WEB

.if ${FLAVOR} == docs
pre-install:
	@${ECHO_MSG} "Removing outdated release notes"
	@${FIND} ${WRKSRC}/news \( -name 'news-[0-3]*' -o -name '*beta*' \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} ; ${CP} AUTHORS ${STAGEDIR}${DOCSDIR} ;\
	       	${CP} COPYING ${STAGEDIR}${DOCSDIR} ;\
	       	${CP} README.md ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs ; ${CP} rpc-spec.md ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/extras ; ${CP} send-email-when-torrent-done.sh ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/news
	@cd ${WRKSRC}/news ; ${CP} -R . ${STAGEDIR}${DOCSDIR}/news
.endif

.if ${FLAVOR} == qt
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA}	${WRKSRC}/qt/icons/transmission.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/transmission-qt.svg
.endif

.if ${FLAVOR} == daemon
post-install:
	        ${MKDIR} ${STAGEDIR}${ETCDIR}/home
.endif

.if ${FLAVOR} == web
do-install:
		( cd ${WRKSRC}/web && ${COPYTREE_SHARE} public_html ${STAGEDIR}${DATADIR} )
.endif

post-install-TESTS-on:
	@${ECHO_MSG} "Running tests..."
	@cd ${BUILD_WRKSRC}/tests/libtransmission/ && \
		eval ${BUILD_WRKSRC}/tests/libtransmission/libtransmission-test \
		--gtest_filter="-DhtTest.usesBootstrapFile" \
		#fails in poudriere due to lack of networking, passes otherwise
		--gtest_brief=1 \

.include <bsd.port.mk>
