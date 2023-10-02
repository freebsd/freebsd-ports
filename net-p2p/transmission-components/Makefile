PORTNAME=	transmission
DISTVERSION=	4.0.4
PORTREVISION=	4
CATEGORIES=	net-p2p

MAINTAINER=	mondo.debater_0q@icloud.com
COMMENT=	Transmission BitTorrent client
WWW=		https://www.transmissionbt.com

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libb64.so:converters/libb64 \
		libcurl.so:ftp/curl \
		libdeflate.so:archivers/libdeflate \
		libdht.so:devel/jech-dht \
		libevent.so:devel/libevent \
		libfmt.so:devel/libfmt \
		libminiupnpc.so:net/miniupnpc \
		libnatpmp.so:net/libnatpmp \
		libpsl.so:dns/libpsl \
		libutp.so:net-p2p/libutp

FLAVORS=			cli docs daemon gtk qt utils
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

USES=		cmake cpe iconv libtool localbase pkgconfig ssl

CPE_VENDOR=	transmissionbt
CPE_PRODUCT=	transmission

USE_GITHUB=	YES
GH_TUPLE=	google:googletest:af29db7:googletest/third-party/googletest \
		transmission:fast_float:6624977:fast_float/third-party/fast_float \
		transmission:utfcpp:b85efd6:utfcpp/third-party/utfcpp \
		transmission:wide-integer:4de0b52:wideinteger/third-party/wide-integer

.if ${FLAVOR} == gtk
USES+=		desktop-file-utils gettext-runtime gettext-tools gnome
USE_GNOME=	gdkpixbuf2 glibmm gtkmm30
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
USES=		cpe
.endif

CMAKE_ARGS=	-DCMAKE_C_STANDARD_INCLUDE_DIRECTORIES=${LOCALBASE}/include \
		-DCMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES=${LOCALBASE}/include \
		-DCMAKE_INSTALL_MANDIR="${PREFIX}/man"
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
CMAKE_OFF+=	ENABLE_CLI ENABLE_GTK ENABLE_QT ENABLE_UTILS
.endif

.if ${FLAVOR} == gtk
CMAKE_ON+=	ENABLE_GTK GTK_IS_REQUIRED
CMAKE_ARGS+=	-DUSE_GTK_VERSION=3
CMAKE_OFF+=	ENABLE_CLI ENABLE_DAEMON ENABLE_UTILS INSTALL_WEB
.endif

.if ${FLAVOR} == qt
CMAKE_ON+=	ENABLE_QT QT_IS_REQUIRED
CMAKE_ARGS+=	-DUSE_QT_VERSION=5
CMAKE_OFF+=	ENABLE_CLI ENABLE_DAEMON ENABLE_UTILS INSTALL_WEB
.endif

.if ${FLAVOR} == utils
CMAKE_ON+=	ENABLE_UTILS
CMAKE_OFF+=	ENABLE_CLI ENABLE_DAEMON ENABLE_GTK ENABLE_QT ENABLE_TESTS \
		ENABLE_WERROR INSTALL_WEB
.endif

OPTIONS_FILE=	${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options

.if ${FLAVOR:Mdaemon}
OPTIONS_DEFINE=		NLS TESTS WEB
OPTIONS_DEFAULT=	NLS WEB
.endif

.if ${FLAVOR:Mdocs}
OPTIONS_DEFINE=
.endif

.if ${FLAVOR:Ndaemon} && ${FLAVOR:Ndocs}
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
WEB_DESC=	Install web client (implies daemon)

NLS_USES=	gettext-runtime:lib
NLS_CMAKE_BOOL=	ENABLE_NLS

TESTS_CMAKE_BOOL=	ENABLE_TESTS

UTILS_CMAKE_BOOL=	ENABLE_UTILS

WEB_CMAKE_BOOL=	INSTALL_WEB

post-extract:
	@${ECHO_MSG} "Cludging use of devel/libfmt as Transmission's CMakeLists.txt does not properly search for it."
	@${MKDIR} ${WRKSRC}/third-party/fmt/include/fmt
	@${LN} -Fs ${PREFIX}/include/fmt ${WRKSRC}/third-party/fmt/include/fmt

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

post-install-TESTS-on:
	@${ECHO_MSG} "Running tests..."
	@cd ${BUILD_WRKSRC}/tests/libtransmission/ && \
		eval ${BUILD_WRKSRC}/tests/libtransmission/libtransmission-test \
		--gtest_filter="-DhtTest.usesBootstrapFile" \
		#fails in poudriere due to lack of networking, passes otherwise
		--gtest_brief=1 \

.include <bsd.port.mk>
