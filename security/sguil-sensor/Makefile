# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	sguil-sensor
PORTVERSION=	0.8.0
CATEGORIES=	security
MASTER_SITES=	SF/sguil/sguil/sguil-${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Sguil is a network security monitoring program

LIB_DEPENDS=	tls:${PORTSDIR}/devel/tcltls
RUN_DEPENDS=	barnyard2:${PORTSDIR}/security/barnyard2-sguil \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:${PORTSDIR}/lang/tclX

OPTIONS_DEFINE=	PADS SANCP
PADS_DESC=	Include pads sensor
SANCP_DESC=	Include sancp sensor

LICENSE_NAME=	QPLv1.0
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.QPL
LICENSE_PERMS=	auto-accept

NO_BUILD=	yes
USE_RC_SUBR=	pcap_agent snort_agent
TCL_VER=	8.5
TCLSH=		tclsh${TCL_VER}
WRKSRC=		${WRKDIR}/sguil-${PORTVERSION}
PATCH_WRKSRC=	${WRKSRC}/sensor
SGUILDIR?=	sguil-sensor
SUB_LIST=	SGUILDIR=${SGUILDIR} TCLSH=${TCLSH}
SUB_FILES=	pkg-message
PLIST_SUB=	SGUILDIR=${SGUILDIR}
AGENTS=		pcap_agent.tcl snort_agent.tcl
CONFS=		pcap_agent.conf snort_agent.conf
LOG_SCRIPTS=	log_packets-daemonlogger.sh log_packets.sh
WITH_PCRE=	true

PORTDOCS1=	README
PORTDOCS2=	README.daemonlogger
PORTDOCS3=	CHANGES FAQ INSTALL INSTALL.openbsd OPENSSL.README \
		TODO UPGRADE USAGE sguildb.dia

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSANCP}
AGENTS+=	sancp_agent.tcl pcap_agent-sancp.tcl
CONFS+=		sancp_agent.conf sancp-indexed.conf pcap_agent-sancp.conf
RUN_DEPENDS+=	sancp:${PORTSDIR}/security/sancp
USE_RC_SUBR+=	sancp_agent pcap_agent-sancp
PLIST_SUB+=	USESANCP=""
.else
PLIST_SUB+=	USESANCP="@comment "
.endif

.if ${PORT_OPTIONS:MPADS}
AGENTS+=	pads_agent.tcl
CONFS+=		pads_agent.conf
RUN_DEPENDS+=	pads:${PORTSDIR}/net-mgmt/pads
USE_RC_SUBR+=	pads_agent
PLIST_SUB+=	USEPADS=""
.else
PLIST_SUB+=	USEPADS="@comment "
.endif

post-patch:
.for f in ${AGENTS}
	@${REINPLACE_CMD} 's|/bin/sh|${STAGEDIR}${PREFIX}/bin/${TCLSH}|' \
		${WRKSRC}/sensor/${f}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/${SGUILDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${SGUILDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${SGUILDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${SGUILDIR}/contrib
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${SGUILDIR}/init
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/sensor/contrib && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/${SGUILDIR}/contrib "! -name ossec_agent.tcl.orig")
	(cd ${WRKSRC}/sensor/init && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/${SGUILDIR}/init)
	${INSTALL_DATA} ${PORTDOCS1:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS2:S|^|${WRKSRC}/sensor/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS3:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
.for f in ${AGENTS}
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/sensor/${f} \
		${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.for f in ${LOG_SCRIPTS}
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/sensor/${f} \
		${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.for f in ${CONFS}
	${INSTALL_DATA} ${WRKSRC}/sensor/${f} \
		${STAGEDIR}${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor
.if ${PORT_OPTIONS:MSANCP}
.for f in log_packets-sancp.sh
	${INSTALL_SCRIPT} -m 751 ${WRKSRC}/sensor/${f} \
		${STAGEDIR}${PREFIX}/bin/${SGUILDIR}/${f}
.endfor
.for f in sancp.conf
	${INSTALL_DATA} ${WRKSRC}/sensor/sancp/${f} \
		${STAGEDIR}${PREFIX}/etc/${SGUILDIR}/${f}-sample
.endfor
.endif
post-install:

.if ${PORT_OPTIONS:MSANCP}
.for f in README.sancp_indexed_pcap
	cd ${WRKSRC}/sensor && ${INSTALL_DATA} ${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
