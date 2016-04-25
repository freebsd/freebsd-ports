# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bro
PORTVERSION=	2.4.1
CATEGORIES=	security
MASTER_SITES=	http://www.bro.org/downloads/release/

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	System for detecting network intruders in real-time

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:devel/bison \
		${LOCALBASE}/bin/swig:devel/swig13
LIB_DEPENDS=	libGeoIP.so:net/GeoIP

USES=		cmake:outsource compiler:c++11-lang perl5 python

CMAKE_ARGS+=	-D PYTHON_EXECUTABLE:PATH=${PYTHON_CMD}
CXXFLAGS+=	-std=c++11 -Wextra -Wall -pedantic

SUB_FILES=	pkg-message
NO_MTREE=	yes

.if defined(BRO_PREFIX)
PREFIX=${BRO_PREFIX}
PLIST_SUB+=	CLEANUP_PREFIX=""
.else
PLIST_SUB+=	CLEANUP_PREFIX="@comment "
.endif
CMAKE_ARGS+=	-D CMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-D BRO_ROOT_DIR:PATH=${PREFIX} \
		-D PY_MOD_INSTALL_DIR:PATH=${PREFIX}/lib/broctl \
		-D BRO_SCRIPT_INSTALL_PATH:PATH=${PREFIX}/share/bro \
		-D BRO_ETC_INSTALL_DIR:PATH=${PREFIX}/etc \
		-D BRO_MAN_INSTALL_PATH=${MANPREFIX}/man \
		-D ENABLE_PERFTOOLS:BOOL=false \
		-D ENABLE_PERFTOOLS_DEBUG:BOOL=false \
		-D BinPAC_SKIP_INSTALL:BOOL=true \
		-D INSTALL_AUX_TOOLS:BOOL=true \
		-D BUILD_SHARED_LIBS:BOOL=true

BROUSER?=	bro
BROGROUP?=	bro
PLIST_SUB+=	BROUSER=${BROUSER} \
		BROGROUP=${BROGROUP}

USERS=		${BROUSER}
GROUPS=		${BROGROUP}

USE_OPENSSL=	yes

OPTIONS_DEFINE= BROCCOLI BROCTL BROKER DEBUG IPSUMDUMP LBL_CF LBL_HF PERFTOOLS PORTS_SSL
OPTIONS_DEFAULT=BROCCOLI BROCTL IPSUMDUMP LBL_CF LBL_HF PORTS_SSL

BROCCOLI_DESC=	Build support for libbroccoli communications
BROCTL_DESC=	Build BroControl support (requires BROCCOLI)
BROKER_DESC=	Enable the Broker communication library
DEBUG_DESC=	Compile in debugging mode
IPSUMDUMP_DESC=	Enables traffic summaries
LBL_CF_DESC=	Unix time to formated time/date filter support
LBL_HF_DESC=	Address to hostname filter support
PERFTOOLS_DESC=	Use Perftools to improve memory & CPU usage
PORTS_SSL_DESC=	Build with OpenSSL from ports (instead of base system)

OPTIONS_EXCLUDE=NLS DOCS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBROCCOLI}
LIB_DEPENDS+=	libbroccoli.so:security/broccoli
.endif

.if ${PORT_OPTIONS:MBROCTL}
.if empty(PORT_OPTIONS:MBROCCOLI)
IGNORE=		the BROCTL option requires BROCCOLI
.endif
.if empty(PORT_OPTIONS:MIPSUMDUMP)
IGNORE=		the BROCTL option requires IPSUMDUMP
.endif
BUILD_DEPENDS+=	${LOCALBASE}/bin/bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
RUN_DEPENDS+=	${LOCALBASE}/bin/bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
PLIST_SUB+=	BROCTL=""
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-D INSTALL_BROCTL:BOOL=true
.else
CMAKE_ARGS+=	-D INSTALL_BROCTL:BOOL=false
PLIST_SUB+=	BROCTL="@comment "
.endif

.if ${PORT_OPTIONS:MBROKER}
CMAKE_ARGS+=	-D ENABLE_BROKER:BOOL=true
BUILD_DEPENDS+=	caf>=0.14.1:devel/caf
PLIST_SUB+=	BROKER=""

.if ${OSVERSION} < 1001000
# Bro 2.4 with BROKER requires caf, clang and libc++
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang++34:lang/clang34 \
		${LOCALBASE}/lib/c++/libstdc++.so:devel/libc++

CXXFLAGS+=	-stdlib=libc++ -I${LOCALBASE}/include/c++/v1 -L${LOCALBASE}/lib
CXX=		${LOCALBASE}/bin/clang++34
.endif
.else
CMAKE_ARGS+=	-D ENABLE_BROKER:BOOL=false
PLIST_SUB+=	BROKER="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-D ENABLE_DEBUG:BOOL=true
.else
CMAKE_ARGS+=	-D ENABLE_DEBUG:BOOL=false
.endif

.if ${PORT_OPTIONS:MLBL_HF}
RUN_DEPENDS+=	${LOCALBASE}/bin/hf:sysutils/lbl-hf
.endif

.if ${PORT_OPTIONS:MLBL_CF}
RUN_DEPENDS+=	${LOCALBASE}/bin/cf:sysutils/lbl-cf
.endif

.if ${PORT_OPTIONS:MPERFTOOLS}
CMAKE_ARGS+=	-D ENABLE_PERFTOOLS:BOOL=true
RUN_DEPENDS+=	${LOCALBASE}/bin/pprof:devel/google-perftools
.else
CMAKE_ARGS+=	-D ENABLE_PERFTOOLS:BOOL=false
.endif

.if ${PORT_OPTIONS:MPORTS_SSL}
CMAKE_ARGS+=	-D CMAKE_EXE_LINKER_FLAGS="${OPENSSL_LDFLAGS}"
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcrypto.so:security/openssl
RUN_DEPENDS+=	${LOCALBASE}/lib/libcrypto.so:security/openssl
.else
.if defined(WITH_OPENSSL_PORT)
IGNORE=		the SSL option is requred when WITH_OPENSSL_PORT is enabled
.endif
.endif

.if ${PORT_OPTIONS:MIPSUMDUMP}
BUILD_DEPENDS+=	ipsumdump:net/ipsumdump
RUN_DEPENDS+=	ipsumdump:net/ipsumdump
.endif

post-install-BROCTL-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/logs
	@${MKDIR} ${STAGEDIR}${PREFIX}/spool/tmp
	@${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/auto
	@${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/site
.for F in broctl.cfg networks.cfg node.cfg
	@${MV} ${STAGEDIR}${PREFIX}/etc/${F} ${STAGEDIR}${PREFIX}/etc/${F}.example
.endfor

.include <bsd.port.post.mk>
