# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bro
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.bro-ids.org/downloads/release/

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	System for detecting network intruders in real-time

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

USES=		cmake:outsource perl5
USE_PYTHON=	yes

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
		-D ENABLE_PERFTOOLS:BOOL=false \
		-D ENABLE_PERFTOOLS_DEBUG:BOOL=false \
		-D BinPAC_SKIP_INSTALL:BOOL=true \
		-D INSTALL_AUX_TOOLS:BOOL=true \
		-D BUILD_SHARED_LIBS:BOOL=true

OPTIONS_DEFINE=	BROCCOLI BROCTL DEBUG IPSUMDUMP LBL_CF LBL_HF PERFTOOLS
OPTIONS_DEFAULT=BROCCOLI BROCTL IPSUMDUMP LBL_CF LBL_HF

BROCCOLI_DESC=	Build support for libbroccoli communications
BROCTL_DESC=	Build BroControl support (requires BROCCOLI)
DEBUG_DESC=	Compile in debugging mode
IPSUMDUMP_DESC=	Enables traffic summaries
LBL_CF_DESC=	Unix time to formated time/date filter support
LBL_HF_DESC=	Address to hostname filter support
PERFTOOLS_DESC=	Use Perftools to improve memory & CPU usage

OPTIONS_EXCLUDE=NLS DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBROCCOLI}
LIB_DEPENDS+=	broccoli:${PORTSDIR}/security/broccoli
.endif

.if ${PORT_OPTIONS:MBROCTL}
.if empty(PORT_OPTIONS:MBROCCOLI)
IGNORE=		the BROCTL option requires BROCCOLI
.endif
.if empty(PORT_OPTIONS:MIPSUMDUMP)
IGNORE=		the BROCTL option requires IPSUMDUMP
.endif
BUILD_DEPENDS+=		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=		bash:${PORTSDIR}/shells/bash
PLIST_SUB+=		BROCTL=""
USE_LDCONFIG=		yes
CMAKE_ARGS+=		-D INSTALL_BROCTL:BOOL=true
.else
CMAKE_ARGS+=		-D INSTALL_BROCTL:BOOL=false
PLIST_SUB+=		BROCTL="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=		-D ENABLE_DEBUG:BOOL=true
.else
CMAKE_ARGS+=		-D ENABLE_DEBUG:BOOL=false
.endif

.if ${PORT_OPTIONS:MLBL_HF}
RUN_DEPENDS+=	hf:${PORTSDIR}/sysutils/lbl-hf
.endif

.if ${PORT_OPTIONS:MLBL_CF}
RUN_DEPENDS+=	cf:${PORTSDIR}/sysutils/lbl-cf
.endif

.if ${PORT_OPTIONS:MPERFTOOLS}
CMAKE_ARGS+=		-D ENABLE_PERFTOOLS:BOOL=true
RUN_DEPENDS+=	pprof:${PORTSDIR}/devel/google-perftools
.else
CMAKE_ARGS+=		-D ENABLE_PERFTOOLS:BOOL=false
.endif

.if ${PORT_OPTIONS:MIPSUMDUMP}
BUILD_DEPENDS+=	ipsumdump:${PORTSDIR}/net/ipsumdump
RUN_DEPENDS+=	ipsumdump:${PORTSDIR}/net/ipsumdump
.endif

post-install:
.if ${PORT_OPTIONS:MBROCTL}
	@${MKDIR} ${PREFIX}/logs
.for i in broctl.cfg networks.cfg node.cfg
	@${MKDIR} ${PREFIX}/etc
	@if [ ! -f ${PREFIX}/etc/${i} ]; then \
		${CP} ${PREFIX}/etc/${i}.sample ${PREFIX}/etc/${i}; \
	fi
.endfor
	@${PREFIX}/bin/broctl install
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
