PORTNAME=	zeek
DISTVERSION=	7.0.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://download.zeek.org/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	System for detecting network intruders in real-time
WWW=		https://www.zeek.org/

LICENSE=	CC-BY-4.0

BUILD_DEPENDS=	bison>=3.3:devel/bison \
		flex>=2.6:textproc/flex \
		swig>=4.0.2:devel/swig
LIB_DEPENDS=	libcares.so:dns/c-ares
RUN_DEPENDS=	c-ares>=1.25.0:dns/c-ares

USES=           bison cmake compiler:c++17-lang cpe perl5 python \
		shebangfix ssl

USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/auxil/c-ares \
			--no-same-owner --no-same-permissions

BINARY_ALIAS=	python3=${PYTHON_CMD}

PORTSCOUT=	limit:^[0-9]*\.0\.

CXXFLAGS_powerpc64=	-mpower8-vector

SHEBANG_FILES=	\
	auxil/broker/bindings/python/3rdparty/pybind11/docs/conf.py \
	auxil/broker/bindings/python/3rdparty/pybind11/setup.py \
	auxil/broker/bindings/python/3rdparty/pybind11/tools/make_changelog.py \
	auxil/broker/bindings/python/3rdparty/pybind11/tools/setup_global.py.in \
	auxil/broker/bindings/python/3rdparty/pybind11/tools/setup_main.py.in \
	auxil/btest/btest \
	auxil/btest/btest-setsid \
	auxil/netcontrol-connectors/acld/acld.py \
	auxil/netcontrol-connectors/command-line/command-line.py \
	auxil/netcontrol-connectors/openflow/controller.py \
	auxil/netcontrol-connectors/test/simple-client.py \
	auxil/package-manager/zkg \
	auxil/spicy/3rdparty/benchmark/tools/compare.py \
	auxil/spicy/3rdparty/benchmark/tools/strip_asm.py \
	auxil/spicy/3rdparty/doctest/scripts/bench/bench.py \
	auxil/spicy/3rdparty/doctest/scripts/bench/run_all.py \
	auxil/spicy/doc/scripts/spicy-doc-to-rst \
	auxil/spicy/tests/Scripts/license-header.py \
	auxil/spicy/tests/Scripts/stray_baselines.py \
	auxil/vcpkg/ports/gobject-introspection/portfile.cmake \
	auxil/zeek-aux/devel-tools/github-manage \
	auxil/zeek-client/man/build.py \
	auxil/zeek-client/zeek-client \
	auxil/zeekctl/ZeekControl/test_cli.py \
	auxil/zeekctl/auxil/pysubnettree/setup.py \
	auxil/zeekctl/auxil/trace-summary/trace-summary \
	auxil/zeekctl/bin/stats-to-csv \
	auxil/zeekctl/bin/zeekctl.in \
	auxil/zeekctl/bin/zeekctld.in \
	auxil/zeekctl/testing/Cfg/bin/zeek__test \
	auxil/zeekctl/testing/Scripts/diff-to-bytes-output \
	auxil/zeekctl/util/extract-strictly-local-conns \
	auxil/zeekctl/util/reformat-stats \
	ci/collect-repo-info.py \
	testing/coverage/coverage_cleanup.py \
	testing/scripts/coverage-calc \
	testing/scripts/httpd.py

SUB_FILES=	pkg-message
NO_MTREE=	yes

CMAKE_ON=	BROKER_DISABLE_DOC_EXAMPLES BROKER_DISABLE_TESTS \
		BUILD_SHARED_LIBS BUILD_STATIC_BROKER INSTALL_AUX_TOOLS
CMAKE_ARGS=	-DCARES_ROOT_DIR:PATH=${PREFIX} \
		-DCMAKE_EXE_LINKER_FLAGS="${OPENSSL_LDFLAGS}" \
		-DDISABLE_JAVASCRIPT:BOOL=ON \
		-DINSTALL_BTEST:BOOL=OFF \
		-DINSTALL_BTEST_PCAPS:BOOL=OFF \
		-DINSTALL_ZKG:BOOL=OFF \
		-DPY_MOD_INSTALL_DIR:PATH=${PREFIX}/lib/zeekctl \
		-DZEEK_ETC_INSTALL_DIR:PATH=${PREFIX}/etc \
		-DZEEK_ROOT_DIR:PATH=${PREFIX} \
		-DZEEK_SCRIPT_INSTALL_PATH:PATH=${PREFIX}/share/zeek

ZEEKUSER?=	zeek
ZEEKGROUP?=	zeek
PLIST_SUB+=	ZEEKGROUP=${ZEEKGROUP} \
		ZEEKUSER=${ZEEKUSER}

USERS=		${ZEEKUSER}
GROUPS=		${ZEEKGROUP}

OPTIONS_DEFINE=	GEOIP2 IPSUMDUMP LBL_CF LBL_HF PERFTOOLS SPICY ZEEKCTL \
		ZKG

OPTIONS_SINGLE=			BUILD_TYPE
OPTIONS_SINGLE_BUILD_TYPE=	DEBUG MINSIZEREL RELEASE RELWITHDEBINFO

OPTIONS_DEFAULT=	GEOIP2 IPSUMDUMP LBL_CF LBL_HF RELEASE ZEEKCTL \
			ZKG
OPTIONS_DEFAULT_aarch64=	SPICY
OPTIONS_DEFAULT_amd64=	SPICY
OPTIONS_DEFAULT_armv6=	SPICY
OPTIONS_DEFAULT_armv7=	SPICY
OPTIONS_DEFAULT_i386=	SPICY
OPTIONS_SUB=		yes

DEBUG_DESC=		Optimizations off, debug symbols/flags on
GEOIP2_DESC=		Build with GeoIP2 (MaxMindDB) support
IPSUMDUMP_DESC=		Enables traffic summaries
LBL_CF_DESC=		Unix time to formated time/date filter support
LBL_HF_DESC=		Address to hostname filter support
MINSIZEREL_DESC=	Optimizations on, debug symbols/flags off
PERFTOOLS_DESC=		Use Perftools to improve memory & CPU usage
RELEASE_DESC=		Optimizations on, debug symbols/flags off
RELWITHDEBINFO_DESC=	Optimizations/debug symbols on, debug flags off
SPICY_DESC=		Enable the Spicy parser generator
ZEEKCTL_DESC=		ZeekControl support (implies IPSUMDUMP)
ZKG_DESC=		Zeek package manager support

ZEEKCTL_IMPLIES=	IPSUMDUMP

GEOIP2_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
IPSUMDUMP_BUILD_DEPENDS=	ipsumdump:net/ipsumdump
IPSUMDUMP_RUN_DEPENDS=		ipsumdump:net/ipsumdump
LBL_CF_RUN_DEPENDS=		${LOCALBASE}/bin/cf:sysutils/lbl-cf
LBL_HF_RUN_DEPENDS=		${LOCALBASE}/bin/hf:sysutils/lbl-hf
PERFTOOLS_BUILD_DEPENDS=	${LOCALBASE}/include/gperftools/tcmalloc.h:devel/google-perftools \
				${LOCALBASE}/bin/pprof:devel/pprof
PERFTOOLS_CMAKE_BOOL=		ENABLE_PERFTOOLS
PERFTOOLS_RUN_DEPENDS=		${LOCALBASE}/lib/libtcmalloc.so.4:devel/google-perftools \
				${LOCALBASE}/bin/pprof:devel/pprof
SPICY_CMAKE_OFF=		-DDISABLE_SPICY=ON
ZEEKCTL_BUILD_DEPENDS=		${LOCALBASE}/bin/bash:shells/bash \
				${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
ZEEKCTL_CMAKE_BOOL=		INSTALL_ZEEKCTL
ZEEKCTL_RUN_DEPENDS=		${LOCALBASE}/bin/bash:shells/bash \
				${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
ZKG_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}zkg>=2.7.1:security/py-zkg@${PY_FLAVOR}
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_BUILD_TYPE=	Debug
STRIP=
.elif ${PORT_OPTIONS:MMINSIZEREL}
CMAKE_BUILD_TYPE=	MinSizeRel
.elif ${PORT_OPTIONS:MRELEASE}
CMAKE_BUILD_TYPE=	Release
.elif ${PORT_OPTIONS:MRELWITHDEBINFO}
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

.if ${PORT_OPTIONS:MZEEKCTL}
USE_RC_SUBR=	zeek
.endif

post-install-ZEEKCTL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/logs
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/tmp
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/auto
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/site
.for F in zeekctl.cfg networks.cfg node.cfg
	${MV} ${STAGEDIR}${PREFIX}/etc/${F} ${STAGEDIR}${PREFIX}/etc/${F}.sample
.endfor
	${RM} ${STAGEDIR}${PREFIX}/share/zeekctl/scripts/zeekctl-config.sh
	${LN} -s ../../../spool/zeekctl-config.sh \
	    ${STAGEDIR}${PREFIX}/share/zeekctl/scripts/zeekctl-config.sh
	${RM} ${STAGEDIR}${PREFIX}/lib/broctl
	${LN} -s zeek/python/zeekctl ${STAGEDIR}${PREFIX}/lib/broctl

post-install:
	${MV} ${STAGEDIR}${DATADIR}/site/local.zeek \
	    ${STAGEDIR}${DATADIR}/site/local.zeek.sample
	@${RM} -rf ${STAGEDIR}${PREFIX}/var
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/zeek-cut

post-install-SPICY-on:
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/hilti/rt/3rdparty/SafeInt/Archive
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/hilti/rt/3rdparty/SafeInt/Test

pre-install-ZEEKCTL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
