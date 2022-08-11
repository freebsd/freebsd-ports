PORTNAME=	zeek
PORTVERSION=	5.0.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://download.zeek.org/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	System for detecting network intruders in real-time

LICENSE=	BSD3CLAUSE

BROKEN_FreeBSD_12_powerpc64=	does not build: error: zero-size array 'names'

BUILD_DEPENDS=	cmake>=3.15.0:devel/cmake

USES=		bison cmake compiler cpe gettext-runtime \
		ninja perl5 python shebangfix ssl

USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

PORTSCOUT=	limit:0,even

CXXFLAGS_powerpc64=	-mpower8-vector

SHEBANG_FILES=	auxil/zeekctl/auxil/trace-summary/trace-summary

SUB_FILES=	pkg-message
NO_MTREE=	yes

CMAKE_ARGS+=	-GNinja \
		-D BUILD_SHARED_LIBS:BOOL=true \
		-D BUILD_STATIC_BROKER:BOOL=true \
		-D BinPAC_SKIP_INSTALL:BOOL=true \
		-D CMAKE_EXE_LINKER_FLAGS="${OPENSSL_LDFLAGS}" \
		-D CMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-D ENABLE_PERFTOOLS_DEBUG:BOOL=false \
		-D INSTALL_AUX_TOOLS:BOOL=true \
		-D PYTHON_EXECUTABLE:PATH=${PYTHON_CMD} \
		-D PY_MOD_INSTALL_DIR:PATH=${PREFIX}/lib/zeekctl \
		-D ZEEK_ETC_INSTALL_DIR:PATH=${PREFIX}/etc \
		-D ZEEK_MAN_INSTALL_PATH=${MANPREFIX}/man \
		-D ZEEK_ROOT_DIR:PATH=${PREFIX} \
		-D ZEEK_SCRIPT_INSTALL_PATH:PATH=${PREFIX}/share/zeek

ZEEKUSER?=	zeek
ZEEKGROUP?=	zeek
PLIST_SUB+=	ARCH=${UNAME_M} \
		LCASE_OPSYS=${OPSYS:tl} \
		ZEEKGROUP=${ZEEKGROUP} \
		ZEEKUSER=${ZEEKUSER}

USERS=		${ZEEKUSER}
GROUPS=		${ZEEKGROUP}

OPTIONS_DEFINE=	BROKER GEOIP2 IPSUMDUMP LBL_CF LBL_HF NETMAP PERFTOOLS \
		SPICY ZEEKCTL ZKG

OPTIONS_SINGLE=			BUILD_TYPE
OPTIONS_SINGLE_BUILD_TYPE=	DEBUG MINSIZEREL RELEASE RELWITHDEBINFO

OPTIONS_DEFAULT=	BROKER GEOIP2 IPSUMDUMP LBL_CF LBL_HF NETMAP RELEASE \
			ZEEKCTL ZKG
OPTIONS_DEFAULT_aarch64=	SPICY
OPTIONS_DEFAULT_amd64=	SPICY
OPTIONS_DEFAULT_armv6=	SPICY
OPTIONS_DEFAULT_armv7=	SPICY
OPTIONS_DEFAULT_i386=	SPICY
OPTIONS_SUB=		yes

BROKER_DESC=		Enable the Broker communication library
DEBUG_DESC=		Optimizations off, debug symbols/flags on
GEOIP2_DESC=		Build with GeoIP2 (MaxMindDB) support
IPSUMDUMP_DESC=		Enables traffic summaries
LBL_CF_DESC=		Unix time to formated time/date filter support
LBL_HF_DESC=		Address to hostname filter support
MINSIZEREL_DESC=	Optimizations on, debug symbols/flags off
NETMAP_DESC=		Native Netmap Packet IOSource for Zeek
PERFTOOLS_DESC=		Use Perftools to improve memory & CPU usage
RELEASE_DESC=		Optimizations on, debug symbols/flags off
RELWITHDEBINFO_DESC=	Optimizations/debug symbols on, debug flags off
SPICY_DESC=		Enable the Spicy parser generator
ZEEKCTL_DESC=		ZeekControl support (implies BROKER and IPSUMDUMP)
ZKG_DESC=		Zeek package manager support

ZEEKCTL_IMPLIES=	BROKER IPSUMDUMP

BROKER_BUILD_DEPENDS=	swig:devel/swig
BROKER_CMAKE_BOOL=	ENABLE_BROKER
GEOIP2_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
IPSUMDUMP_BUILD_DEPENDS=ipsumdump:net/ipsumdump
IPSUMDUMP_RUN_DEPENDS=	ipsumdump:net/ipsumdump
LBL_CF_RUN_DEPENDS=	${LOCALBASE}/bin/cf:sysutils/lbl-cf
LBL_HF_RUN_DEPENDS=	${LOCALBASE}/bin/hf:sysutils/lbl-hf
NETMAP_GH_TUPLE=	zeek:zeek-netmap:v2.0.0:zeek_netmap
NETMAP_USE=		GITHUB=nodefault
PERFTOOLS_BUILD_DEPENDS=${LOCALBASE}/bin/perftools-pprof:devel/google-perftools
PERFTOOLS_CMAKE_BOOL=	ENABLE_PERFTOOLS
PERFTOOLS_RUN_DEPENDS=${LOCALBASE}/bin/perftools-pprof:devel/google-perftools
PYTHON_BUILD_DEPENDS=	swig:devel/swig
SPICY_CMAKE_OFF=	-DDISABLE_SPICY=ON
SPICY_BUILD_DEPENDS=	bison>=3.3:devel/bison \
			flex>=2.6:textproc/flex
ZEEKCTL_BUILD_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
			swig:devel/swig
ZEEKCTL_CMAKE_BOOL=	INSTALL_ZEEKCTL
ZEEKCTL_RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
ZKG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zkg>=2.7.1:security/py-zkg@${PY_FLAVOR} \

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

post-patch:
	${REINPLACE_CMD} -e '\|/usr/local/|s|$$| ${STAGEDIR}${PREFIX}/|' \
	    ${WRKSRC_zeek_netmap}/cmake/FindNetmap.cmake

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

post-install:
	${MV} ${STAGEDIR}${DATADIR}/site/local.zeek \
	    ${STAGEDIR}${DATADIR}/site/local.zeek.sample

pre-install-ZEEKCTL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d

post-install-NETMAP-on:
	${MKDIR} ${WRKDIR}/zeek-bin
	${CP} ${STAGEDIR}${PREFIX}/bin/zeek-config ${WRKDIR}/zeek-bin
	${REINPLACE_CMD} -e 's|${PREFIX}|${STAGEDIR}${PREFIX}|g' \
	    ${WRKDIR}/zeek-bin/zeek-config
	cd ${WRKSRC_zeek_netmap} && ${SETENV} PATH=${WRKDIR}/zeek-bin:${PATH} \
	    ./configure --with-netmap=/usr \
	    --install-root=${STAGEDIR}${PREFIX}/lib/zeek/plugins
	cd ${WRKSRC_zeek_netmap}/build && make && make install

.include <bsd.port.pre.mk>

# Would like to use ARCH (uname -p) but it's not always correct (e.g. arm64)
UNAME_M!=	${UNAME} -m

.include <bsd.port.post.mk>
