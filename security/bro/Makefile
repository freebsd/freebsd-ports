# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bro
PORTVERSION=	2.5.3
CATEGORIES=	security
MASTER_SITES=	https://www.bro.org/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	System for detecting network intruders in real-time

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build: error: zero-size array 'names'

LIB_DEPENDS=	libGeoIP.so:net/GeoIP

USES=		bison cmake:outsource compiler:c++11-lang ninja perl5 python shebangfix ssl

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:PATH=${PYTHON_CMD}
CXXFLAGS+=	-std=c++11 -Wall

STAGEDIR2=	${STAGEDIR}-caf

SHEBANG_FILES=	aux/broctl/aux/trace-summary/trace-summary

SUB_FILES=	pkg-message
NO_MTREE=	yes

CMAKE_ARGS+=	-GNinja \
		-D CMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-D BRO_ROOT_DIR:PATH=${PREFIX} \
		-D PY_MOD_INSTALL_DIR:PATH=${PREFIX}/lib/broctl \
		-D BRO_SCRIPT_INSTALL_PATH:PATH=${PREFIX}/share/bro \
		-D BRO_ETC_INSTALL_DIR:PATH=${PREFIX}/etc \
		-D BRO_MAN_INSTALL_PATH=${MANPREFIX}/man \
		-D ENABLE_PERFTOOLS:BOOL=false \
		-D ENABLE_PERFTOOLS_DEBUG:BOOL=false \
		-D BinPAC_SKIP_INSTALL:BOOL=true \
		-D INSTALL_AUX_TOOLS:BOOL=true \
		-D BUILD_SHARED_LIBS:BOOL=true \
		-D CMAKE_EXE_LINKER_FLAGS="${OPENSSL_LDFLAGS}"

BROUSER?=	bro
BROGROUP?=	bro
PLIST_SUB+=	ARCH=${ARCH} \
		BROUSER=${BROUSER} \
		BROGROUP=${BROGROUP} \
		LCASE_OPSYS=${OPSYS:tl}

USERS=		${BROUSER}
GROUPS=		${BROGROUP}

OPTIONS_DEFINE=	BROCCOLI BROCTL BROKER DEBUG IPSUMDUMP LBL_CF LBL_HF \
		NETMAP PERFTOOLS
OPTIONS_DEFAULT=BROCCOLI BROCTL IPSUMDUMP LBL_CF LBL_HF NETMAP
OPTIONS_SUB=	yes

BROCCOLI_DESC=	Build support for libbroccoli communications
BROCTL_DESC=	BroControl support (implies BROCCOLI and IPSUMDUMP)
BROKER_DESC=	Enable the Broker communication library
IPSUMDUMP_DESC=	Enables traffic summaries
LBL_CF_DESC=	Unix time to formated time/date filter support
LBL_HF_DESC=	Address to hostname filter support
PERFTOOLS_DESC=	Use Perftools to improve memory & CPU usage

BROCTL_IMPLIES=		BROCCOLI IPSUMDUMP

BROCCOLI_LIB_DEPENDS=	libbroccoli.so:security/broccoli
BROCTL_BUILD_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
			swig3.0:devel/swig30
BROCTL_RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
BROCTL_CMAKE_BOOL=	INSTALL_BROCTL
BROCTL_USE=		LDCONFIG=yes
IPSUMDUMP_BUILD_DEPENDS=ipsumdump:net/ipsumdump
IPSUMDUMP_RUN_DEPENDS=	ipsumdump:net/ipsumdump
BROKER_BUILD_DEPENDS=	swig3.0:devel/swig30
BROKER_CMAKE_BOOL=	ENABLE_BROKER
BROKER_CMAKE_ON+=	-DCAF_ROOT_DIR=${STAGEDIR2}${PREFIX}
BROKER_GH_TUPLE=	actor-framework:actor-framework:0.14.6:actor_framework
BROKER_USE=		GITHUB=nodefault
DEBUG_CMAKE_BOOL=	ENABLE_DEBUG
LBL_HF_RUN_DEPENDS=	${LOCALBASE}/bin/hf:sysutils/lbl-hf
LBL_CF_RUN_DEPENDS=	${LOCALBASE}/bin/cf:sysutils/lbl-cf
NETMAP_GH_TUPLE=	bro:bro-netmap:cf88debf487b31ab30dc3b5bac64783b4e49997e:bro_netmap
NETMAP_USE=		GITHUB=nodefault
PERFTOOLS_CMAKE_BOOL=	ENABLE_PERFTOOLS
PERFTOOLS_RUN_DEPENDS=	${LOCALBASE}/bin/perftools-pprof:devel/google-perftools
PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBROCTL}
USE_RC_SUBR=	bro
.endif

CMAKE_ARGS2=		-GNinja \
			-D CMAKE_INSTALL_PREFIX:PATH=${STAGEDIR2}${PREFIX} \
			-D CAF_BUILD_STATIC_ONLY:BOOL=yes \
			-D CAF_LOG_LEVEL:STRING=0 \
			-D CAF_NO_EXAMPLES:BOOL=yes \
			-D CAF_NO_OPENCL:BOOL=yes \
			-D CAF_NO_UNIT_TESTS:BOOL=yes

CONFIGURE_WRKSRC2=	${WRKDIR}/.build-caf
BUILD_WRKSRC2=		${CONFIGURE_WRKSRC2}
INSTALL_WRKSRC2=	${CONFIGURE_WRKSRC2}

# Build the version of caf this version of bro requires
pre-configure-BROKER-on:
	${MKDIR} ${CONFIGURE_WRKSRC2}
	(cd ${CONFIGURE_WRKSRC2} && \
	    ${CMAKE_BIN} ${CMAKE_ARGS2} ${WRKSRC_actor_framework})
	${MKDIR} ${STAGEDIR2}
	(cd ${BUILD_WRKSRC2} && \
	    ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} install)
	${LN} -s libcaf_core_static.a ${STAGEDIR2}${PREFIX}/lib/libcaf_core.a
	${LN} -s libcaf_io_static.a ${STAGEDIR2}${PREFIX}/lib/libcaf_io.a

post-install-BROCTL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/logs
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/tmp
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/auto
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/site
.for F in broctl.cfg networks.cfg node.cfg
	${MV} ${STAGEDIR}${PREFIX}/etc/${F} ${STAGEDIR}${PREFIX}/etc/${F}.example
.endfor

pre-install-BROCTL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d

post-build-NETMAP-on:
	${LN} -s ../.build ${WRKSRC}/build
	(cd ${WRKSRC_bro_netmap} && ./configure --bro-dist=${WRKSRC} \
	    --install-root=${STAGEDIR}${PREFIX}/lib/bro/plugins && \
	    make && make install)

.include <bsd.port.mk>
