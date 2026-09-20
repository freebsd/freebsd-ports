PORTNAME=	netdata
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/:netdata \
		https://dl.nkeor.me/freebsd/netdata/:dashboard \
		https://www.sqlite.org/${SQLITE_VERSION_YEAR}/:sqlite
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:netdata \
		sqlite-src-${SQLITE_VERSION_NUMBER}.zip:sqlite
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:C/:[^:]+$//:Nsqlite-src-*.zip}

MAINTAINER=	nk@nkeor.me
COMMENT=	Scalable distributed realtime performance and health monitoring
WWW=		https://github.com/netdata/netdata

LICENSE=	GPLv3
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE

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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		bash:shells/bash

USES=		cmake compiler:c++17-lang cpe localbase:ldflags pathfix \
		pkgconfig:both python shebangfix ssl

USE_GITHUB=	nodefault
.include "Makefile.tuples"

USE_RC_SUBR=	${PORTNAME}
SHEBANG_GLOB=	*

# The Go plugins are built by CMake, not by the ports Go target
CONFIGURE_ENV+=	${GO_ENV}
MAKE_ENV+=	${GO_ENV}

CMAKE_ON=	DISABLE_HARDENING ENABLE_LIBBACKTRACE

CMAKE_OFF=	ENABLE_NETDATA_JOURNAL_FILE_READER ENABLE_PLUGIN_CGROUP_NETWORK \
		ENABLE_PLUGIN_DEBUGFS ENABLE_PLUGIN_EBPF ENABLE_PLUGIN_IBM \
		ENABLE_PLUGIN_LOCAL_LISTENERS ENABLE_PLUGIN_NETFLOW \
		ENABLE_PLUGIN_NETWORK_VIEWER ENABLE_PLUGIN_NFACCT \
		ENABLE_PLUGIN_OTEL ENABLE_PLUGIN_PERF ENABLE_PLUGIN_SLABINFO \
		ENABLE_PLUGIN_SYSTEMD_JOURNAL ENABLE_PLUGIN_XENSTAT

CFLAGS+=	-D_WANT_VMMETER

EXTRACT_AFTER_ARGS=	--exclude ml/dlib \
	--exclude collectors/python.d.plugin/python_modules/pyyaml2 \
	--exclude collectors/python.d.plugin/python_modules/pyyaml3 \
	--exclude collectors/python.d.plugin/python_modules/urllib3 \
	--no-same-owner --no-same-permissions

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

# Keep in sync with packaging/cmake/Modules/NetdataSQLite.cmake
SQLITE_VERSION_NUMBER=	3530400
SQLITE_VERSION_YEAR=	2026

# Upstream only publishes a rolling, unversioned agent.tar.gz
NETDATA_DASHBOARD_VERSION=	20260115

PLIST_SUB=	NETDATA_CACHE=${NETDATA_CACHE} \
		NETDATA_LOG=${NETDATA_LOG} \
		NETDATA_PERST=${NETDATA_PERST} \
		NETDATA_RUN=${NETDATA_RUN}

OPTIONS_DEFINE=		CUPS DASHBOARD FREEIPMI GOPLUGIN ML PROMETHEUS
OPTIONS_DEFAULT=	DASHBOARD GOPLUGIN ML
OPTIONS_SUB=		yes

CUPS_DESC=		Enable support for cups
DASHBOARD_DESC=		Enable agent dashboard
FREEIPMI_DESC=		Enable support for freeipmi
GOPLUGIN_DESC=		Enable the Go based collector plugins
ML_DESC=		Enable anomaly detection via dlib
PROMETHEUS_DESC=	Enable prometheus remote write exporter

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CMAKE_BOOL=	ENABLE_PLUGIN_CUPS

DASHBOARD_DISTFILES=	agent_${NETDATA_DASHBOARD_VERSION}.tar.gz:dashboard
DASHBOARD_CMAKE_BOOL=	ENABLE_DASHBOARD

FREEIPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
FREEIPMI_CMAKE_BOOL=	ENABLE_PLUGIN_FREEIPMI

GOPLUGIN_USES=		go:no_targets,modules
GOPLUGIN_CMAKE_BOOL=	ENABLE_PLUGIN_GO ENABLE_PLUGIN_SCRIPTS

ML_LIB_DEPENDS=		libdlib.so:science/dlib-cpp
ML_CMAKE_BOOL=		ENABLE_ML

PROMETHEUS_LIB_DEPENDS=	libabsl_base.so:devel/abseil \
			libprotobuf.so:devel/protobuf \
			libsnappy.so:archivers/snappy
PROMETHEUS_CMAKE_BOOL=	ENABLE_EXPORTER_PROMETHEUS_REMOTE_WRITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDASHBOARD}
LICENSE+=			NCUL1
LICENSE_COMB=			multi
LICENSE_NAME_NCUL1=		Netdata Cloud UI License v1.0
LICENSE_FILE_NCUL1=		${WRKDIR}/dist/agent/v3/LICENSE.md
LICENSE_PERMS_NCUL1=		dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES_NCUL1=	agent_${NETDATA_DASHBOARD_VERSION}.tar.gz

CMAKE_ARGS+=	-DDASHBOARD_URL=file://${DISTDIR}/${DIST_SUBDIR}/agent_${NETDATA_DASHBOARD_VERSION}.tar.gz
.endif

pre-patch:
	@${REINPLACE_CMD} -e '\
		s|usr/share/|share/|g; \
		s|DESTINATION usr/libexec/|DESTINATION libexec/|g; \
		s|DESTINATION usr/lib/|DESTINATION lib/|g; \
		s|DESTINATION usr/sbin/|DESTINATION sbin/|g' \
	    ${WRKSRC}/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${PATCH_WRKSRC}/packaging/cmake/Modules/NetdataBacktrace.cmake
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/packaging/cmake/Modules/NetdataVersion.cmake
	@${REINPLACE_CMD} -e \
	    's|%%SQLITE_ARCHIVE%%|file://${DISTDIR}/${DIST_SUBDIR}/sqlite-src-${SQLITE_VERSION_NUMBER}.zip|' \
	    ${PATCH_WRKSRC}/packaging/cmake/Modules/NetdataSQLite.cmake
	@${REINPLACE_CMD} -e '\
		s|%%NETDATA_CACHE%%|${NETDATA_CACHE}|g; \
		s|%%NETDATA_LOG%%|${NETDATA_LOG}|g; \
		s|%%NETDATA_PERST%%|${NETDATA_PERST}|g; \
		s|%%ETCDIR%%|${ETCDIR}|g' \
	    ${PATCH_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g' \
	    ${PATCH_WRKSRC}/src/collectors/python.d.plugin/python.d.plugin.in

post-patch-GOPLUGIN-on:
	${INSTALL_DATA} ${FILESDIR}/go-vendor-modules.txt \
	    ${WRKSRC}/src/go/vendor/modules.txt
	${INSTALL_DATA} ${FILESDIR}/ndmcp-vendor-modules.txt \
	    ${WRKSRC}/src/web/mcp/bridges/stdio-golang/vendor/modules.txt

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		 ${STAGEDIR}${NETDATA_CACHE} \
		 ${STAGEDIR}${NETDATA_LOG} \
		 ${STAGEDIR}${NETDATA_PERST} \
		 ${STAGEDIR}${NETDATA_PERST}/cloud.d \
		 ${STAGEDIR}${NETDATA_PERST}/registry \
		 ${STAGEDIR}${NETDATA_RUN}
	${INSTALL_DATA} ${WRKDIR}/netdata.conf.sample ${STAGEDIR}${ETCDIR}/netdata.conf.sample
	${INSTALL_DATA} ${FILESDIR}/netdata.newsyslog.conf.sample ${STAGEDIR}${ETCDIR}/netdata.newsyslog.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/netdata_required.sample ${STAGEDIR}${PREFIX}/etc/rc.d
	${TOUCH} ${STAGEDIR}${ETCDIR}/.opt-out-from-anonymous-statistics
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/netdata-updater.sh \
		 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/conf.d/netdata-updater.conf \
		 ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/system \
		 ${STAGEDIR}${PREFIX}/var
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} -type f -name "*.conf" -exec ${MV} {} {}.sample \;

# Dashboard file names carry content hashes, so list them dynamically
post-install-DASHBOARD-on:
	@${FIND} ${STAGEDIR}${DATADIR}/web -type f -a ! -name 'netdata-swagger.*' | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
