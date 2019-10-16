# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bro
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.zeek.org/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	System for detecting network intruders in real-time

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build: error: zero-size array 'names'

USES=		bison cmake compiler:c++11-lang gettext-runtime ninja perl5 python shebangfix ssl

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:PATH=${PYTHON_CMD}
CXXFLAGS+=	-std=c++11 -Wall

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
		-D BUILD_STATIC_BROKER:BOOL=true \
		-D CMAKE_EXE_LINKER_FLAGS="${OPENSSL_LDFLAGS}"

BROUSER?=	bro
BROGROUP?=	bro
PLIST_SUB+=	ARCH=${ARCH} \
		BROUSER=${BROUSER} \
		BROGROUP=${BROGROUP} \
		LCASE_OPSYS=${OPSYS:tl}

USERS=		${BROUSER}
GROUPS=		${BROGROUP}

OPTIONS_DEFINE=	BROCCOLI BROCTL BROKER DEBUG GEOIP2 IPSUMDUMP LBL_CF \
		LBL_HF NETMAP PERFTOOLS
OPTIONS_DEFAULT=BROCTL BROKER GEOIP2 IPSUMDUMP LBL_CF LBL_HF NETMAP
OPTIONS_SUB=	yes

BROCCOLI_DESC=	Build support for libbroccoli communications (DEPRECATED)
BROCTL_DESC=	BroControl support (implies BROKER and IPSUMDUMP)
BROKER_DESC=	Enable the Broker communication library
GEOIP2_DESC=	Build with GeoIP2 (MaxMindDB) support
IPSUMDUMP_DESC=	Enables traffic summaries
LBL_CF_DESC=	Unix time to formated time/date filter support
LBL_HF_DESC=	Address to hostname filter support
NETMAP_DESC=	Native Netmap Packet IOSource for Bro
PERFTOOLS_DESC=	Use Perftools to improve memory & CPU usage

BROCTL_IMPLIES=		BROKER IPSUMDUMP

BROCCOLI_LIB_DEPENDS=	libbroccoli.so:security/broccoli
BROCTL_BUILD_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
			swig3.0:devel/swig30
BROCTL_RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
BROCTL_CMAKE_BOOL=	INSTALL_BROCTL
GEOIP2_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
IPSUMDUMP_BUILD_DEPENDS=ipsumdump:net/ipsumdump
IPSUMDUMP_RUN_DEPENDS=	ipsumdump:net/ipsumdump
BROKER_BUILD_DEPENDS=	swig3.0:devel/swig30
BROKER_CMAKE_BOOL=	ENABLE_BROKER
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

post-install-BROCTL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/logs
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/tmp
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/auto
	${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/site
.for F in broctl.cfg networks.cfg node.cfg
	${MV} ${STAGEDIR}${PREFIX}/etc/${F} ${STAGEDIR}${PREFIX}/etc/${F}.example
.endfor
	${RM} ${STAGEDIR}${PREFIX}/share/broctl/scripts/broctl-config.sh
	${LN} -s ../../../spool/broctl-config.sh \
	    ${STAGEDIR}${PREFIX}/share/broctl/scripts/broctl-config.sh

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/bro/cmake

pre-install-BROCTL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d

post-build-NETMAP-on:
	${LN} -s ../.build ${WRKSRC}/build
	(cd ${WRKSRC_bro_netmap} && ./configure --bro-dist=${WRKSRC} \
	    --install-root=${STAGEDIR}${PREFIX}/lib/bro/plugins && \
	    make && make install)

.include <bsd.port.mk>
