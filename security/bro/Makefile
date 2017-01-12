# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bro
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.bro.org/downloads/release/

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	System for detecting network intruders in real-time

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:devel/bison \
		${LOCALBASE}/bin/swig:devel/swig13
LIB_DEPENDS=	libGeoIP.so:net/GeoIP

USES=		cmake:outsource compiler:c++11-lang perl5 python ssl

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
		-D BUILD_SHARED_LIBS:BOOL=true \
		-D CMAKE_EXE_LINKER_FLAGS="${OPENSSL_LDFLAGS}"

BROUSER?=	bro
BROGROUP?=	bro
PLIST_SUB+=	BROUSER=${BROUSER} \
		BROGROUP=${BROGROUP}

USERS=		${BROUSER}
GROUPS=		${BROGROUP}

OPTIONS_DEFINE= BROCCOLI BROCTL BROKER DEBUG IPSUMDUMP LBL_CF LBL_HF PERFTOOLS
OPTIONS_DEFAULT=BROCCOLI BROCTL IPSUMDUMP LBL_CF LBL_HF
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
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
BROCTL_RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
BROCTL_CMAKE_BOOL=	INSTALL_BROCTL
BROCTL_USE=		LDCONFIG=yes
IPSUMDUMP_BUILD_DEPENDS=ipsumdump:net/ipsumdump
IPSUMDUMP_RUN_DEPENDS=	ipsumdump:net/ipsumdump
BROKER_CMAKE_BOOL=	ENABLE_BROKER
BROKER_BUILD_DEPENDS=	caf>=0.14.1:devel/caf
DEBUG_CMAKE_BOOL=	ENABLE_DEBUG
LBL_HF_RUN_DEPENDS=	${LOCALBASE}/bin/hf:sysutils/lbl-hf
LBL_CF_RUN_DEPENDS=	${LOCALBASE}/bin/cf:sysutils/lbl-cf
PERFTOOLS_CMAKE_BOOL=	ENABLE_PERFTOOLS
PERFTOOLS_RUN_DEPENDS=	${LOCALBASE}/bin/pprof:devel/google-perftools

post-install-BROCTL-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/logs
	@${MKDIR} ${STAGEDIR}${PREFIX}/spool/tmp
	@${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/auto
	@${MKDIR} ${STAGEDIR}${PREFIX}/spool/installed-scripts-do-not-touch/site
.for F in broctl.cfg networks.cfg node.cfg
	@${MV} ${STAGEDIR}${PREFIX}/etc/${F} ${STAGEDIR}${PREFIX}/etc/${F}.example
.endfor

.include <bsd.port.mk>
