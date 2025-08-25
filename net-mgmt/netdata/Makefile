PORTNAME=	netdata
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.3
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/:netdata \
		https://raw.githubusercontent.com/netdata/netdata/refs/tags/v${DISTVERSION}/src/go/:goplugin \
		https://dl.nkeor.me/freebsd/netdata/:nkeor
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:netdata
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nk@nkeor.me
COMMENT=	Scalable distributed realtime performance and health monitoring
WWW=		https://github.com/netdata/netdata

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libbacktrace.a:devel/libbacktrace
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libbrotlicommon.so:archivers/brotli \
		libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c \
		liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2 \
		libprotobuf.so:devel/protobuf \
		libuuid.so:misc/libuuid \
		libuv.so:devel/libuv \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		bash:shells/bash

USES=		cmake compiler:c++17-lang cpe localbase:ldflags \
		pathfix pkgconfig:both python shebangfix ssl
USE_GITHUB=	nodefault
USE_RC_SUBR=	${PORTNAME}
SHEBANG_GLOB=	*

CMAKE_ON=	DISABLE_HARDENING ENABLE_DASHBOARD ENABLE_LIBBACKTRACE
# DebugFS and below are Linux exclusive
CMAKE_OFF=	ENABLE_PLUGIN_EBPF \
		ENABLE_PLUGIN_NFACCT \
		ENABLE_PLUGIN_XENSTAT \
		ENABLE_PLUGIN_DEBUGFS \
		ENABLE_PLUGIN_PERF \
		ENABLE_PLUGIN_SLABINFO \
		ENABLE_PLUGIN_SYSTEMD_JOURNAL \
		ENABLE_PLUGIN_CGROUP_NETWORK \
		ENABLE_PLUGIN_LOCAL_LISTENERS \
		ENABLE_PLUGIN_NETWORK_VIEWER

CFLAGS+=	-D_WANT_VMMETER

# Libs that you can't unbundle...
# SQLite3, --exclude database/sqlite/sqlite3*
# (lib)judy, --exclude libnetdata/libjudy
EXTRACT_AFTER_ARGS=	--exclude ml/dlib \
	--exclude collectors/python.d.plugin/python_modules/pyyaml2 \
	--exclude collectors/python.d.plugin/python_modules/pyyaml3 \
	--exclude collectors/python.d.plugin/python_modules/urllib3

SUB_FILES=	${PORTNAME}.conf.sample
SUB_LIST=	NETDATA_CACHE=${NETDATA_CACHE} \
		NETDATA_LOG=${NETDATA_LOG} \
		NETDATA_PERST=${NETDATA_PERST} \
		NETDATA_RUN=${NETDATA_RUN}

USERS=		netdata
GROUPS=		netdata

NETDATA_CACHE=	/var/cache/${PORTNAME}
NETDATA_LOG=	/var/log/${PORTNAME}
NETDATA_PERST=	/var/db/${PORTNAME}
NETDATA_RUN=	/var/run/${PORTNAME}
NETDATA_DASHBOARD_VERSION=	20250824

PLIST_SUB=	NETDATA_CACHE=${NETDATA_CACHE} \
		NETDATA_LOG=${NETDATA_LOG} \
		NETDATA_PERST=${NETDATA_PERST} \
		NETDATA_RUN=${NETDATA_RUN}

OPTIONS_DEFINE=		CUPS DASHBOARD FREEIPMI GOPLUGIN ML PROMETHEUS
OPTIONS_DEFAULT=	DASHBOARD GOPLUGIN ML
OPTIONS_SUB=		YES

CUPS_DESC=		Enable support for cups
DASHBOARD_DESC=		Enable agent dashboard
FREEIPMI_DESC=		Enable support for freeipmi
GOPLUGIN_DESC=		Enable the go collector plugin
ML_DESC=		Enable anomaly detection via dlib
PROMETHEUS_DESC=	Enable prometheus remote write exporter
CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	ENABLE_PLUGIN_CUPS
DASHBOARD_DISTFILES=	agent_${NETDATA_DASHBOARD_VERSION}.tar.gz:nkeor
DASHBOARD_EXTRACT_ONLY=	agent_${NETDATA_DASHBOARD_VERSION}.tar.gz
FREEIPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
FREEIPMI_CMAKE_BOOL=	ENABLE_PLUGIN_FREEIPMI
GOPLUGIN_DISTFILES=	go.mod:goplugin
GOPLUGIN_FETCH_DEPENDS=	go${GO_SUFFIX}:lang/go${GO_SUFFIX}
GOPLUGIN_USES=		go:no_targets,modules
GOPLUGIN_CMAKE_BOOL=	ENABLE_PLUGIN_GO
ML_BUILD_DEPENDS=	${LOCALBASE}/include/dlib/matrix.h:science/dlib-cpp
ML_CMAKE_BOOL=		ENABLE_ML
PROMETHEUS_LIB_DEPENDS=	libsnappy.so:archivers/snappy \
			libabsl_base.so:devel/abseil \
			libprotobuf.so:devel/protobuf
PROMETHEUS_CMAKE_BOOL=	ENABLE_EXPORTER_PROMETHEUS_REMOTE_WRITE

post-fetch-GOPLUGIN-on:
	@(cd ${DISTDIR}/${DIST_SUBDIR}; \
		${SETENVI} ${WRK_ENV} \
		${GO_ENV} GOPROXY=${GO_GOPROXY} ${GO_CMD} mod download -x all)

post-extract-GOPLUGIN-on:
	@${ECHO_MSG} "===> Tidying god.plugin dependencies";
	@(cd ${WRKSRC}/src/go; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e)
	@${ECHO_MSG} "===> Vendoring god.plugin dependencies";
	@(cd ${WRKSRC}/src/go; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod vendor -e)

pre-patch:
	@${REINPLACE_CMD} -e '\
		s|usr/lib/|lib/|g; \
		s|usr/libexec/|libexec/|g; \
		s|usr/share/|share/|g' \
	    ${WRKSRC}/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${PATCH_WRKSRC}/packaging/cmake/Modules/NetdataBacktrace.cmake
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/packaging/cmake/Modules/NetdataVersion.cmake
	@${REINPLACE_CMD} -e '\
		s|%%NETDATA_CACHE%%|${NETDATA_CACHE}|g; \
		s|%%NETDATA_LOG%%|${NETDATA_LOG}|g; \
		s|%%NETDATA_PERST%%|${NETDATA_PERST}|g; \
		s|%%NETDATA_RUN%%|${NETDATA_RUN}|g; \
		s|%%ETCDIR%%|${ETCDIR}|g' \
	    ${PATCH_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g' \
	    ${PATCH_WRKSRC}/src/collectors/python.d.plugin/python.d.plugin.in

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		 ${STAGEDIR}${NETDATA_CACHE} \
		 ${STAGEDIR}${NETDATA_LOG} \
		 ${STAGEDIR}${NETDATA_PERST}
	${INSTALL_DATA} ${WRKDIR}/netdata.conf.sample ${STAGEDIR}${ETCDIR}/netdata.conf.sample
	${INSTALL_DATA} ${FILESDIR}/netdata.newsyslog.conf.sample ${STAGEDIR}${ETCDIR}/netdata.newsyslog.conf.sample
	${TOUCH} ${STAGEDIR}${ETCDIR}/.opt-out-from-anonymous-statistics
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/netdata-updater.sh \
		 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/conf.d/netdata-updater.conf \
		 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/system
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} -type f -name "*.conf" -exec ${MV} {} {}.sample \;

post-install-DASHBOARD-on:
	@(cd ${WRKDIR}/dist/agent && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR}/web)

.include <bsd.port.mk>
