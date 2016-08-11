# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	sguil
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sguil is a network security monitoring program

LICENSE=	GPLv3

RUN_DEPENDS=	tcltls>=0:devel/tcltls \
		${LOCALBASE}/lib/tclx8.4/tclx.tcl:lang/tclX

USE_GITHUB=	yes
GH_ACCOUNT=	bammv

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	SERVER CLIENT SENSOR
OPTIONS_MULTI=		INSTANCE
OPTIONS_MULTI_INSTANCE=	SERVER CLIENT SENSOR
OPTIONS_GROUP=		SERVER CLIENT SENSOR
OPTIONS_GROUP_SERVER=	MYSQL
OPTIONS_GROUP_CLIENT=	AUDIO SANCP WIRESHARK
OPTIONS_GROUP_SENSOR=	PADS_SENSOR SANCP_SENSOR
OPTIONS_SUB=		yes

SERVER_DESC=		Install Sguil Server
CLIENT_DESC=		Install Sguil Client
SENSOR_DESC=		Install Sguil SENSOR
MYSQL_DESC=		Depend on databases/mysqltcl
AUDIO_DESC=		Install Festival Speech Synthesis
SANCP_DESC=		Use sancp
PADS_SENSOR_DESC=	Include pads sensor
SANCP_SENSOR_DESC=	Include sancp sensor
WIRESHARK_DESC=		Install wireshark

CLIENT_USES=		tk:wrapper
SERVER_RUN_DEPENDS=	p0f:net-mgmt/p0f \
	                tcpflow:net/tcpflow \
	                dtplite:devel/tcllib
CLIENT_RUN_DEPENDS=	dtplite:devel/tcllib \
			iwidgets>0:x11-toolkits/iwidgets \
			gpg2:security/gnupg
SENSOR_RUN_DEPENDS=	barnyard2:security/barnyard2-sguil
MYSQL_LIB_DEPENDS=	mysqltcl>=3.052:databases/mysqltcl
AUDIO_RUN_DEPENDS=	festival:audio/festival
SANCP_RUN_DEPENDS=	sancp:security/sancp
WIRESHARK_RUN_DEPENDS=	wireshark:net/wireshark
PADS_SENSOR_RUN_DEPENDS=	pads:net-mgmt/pads
SANCP_SENSOR_RUN_DEPENDS=	sancp:security/sancp

NO_BUILD=	yes
TCL_VER=	8.5
TCLSH=		tclsh${TCL_VER}
SERVER_SGUILDIR?=	sguild
CLIENT_SGUILDIR?=	sguil-client
SENSOR_SGUILDIR?=	sguil-sensor
PLIST_SUB=	SERVER_SGUILDIR=${SERVER_SGUILDIR} \
		CLIENT_SGUILDIR=${CLIENT_SGUILDIR} \
		SENSOR_SGUILDIR=${SENSOR_SGUILDIR}
SUB_LIST=	SERVER_SGUILDIR=${SERVER_SGUILDIR} TCLSH=${TCLSH} \
		CLIENT_SGUILDIR=${CLIENT_SGUILDIR} \
		SENSOR_SGUILDIR=${SENSOR_SGUILDIR}
SERVER_CONFS=	autocat.conf sguild.access sguild.email	sguild.reports \
		sguild.conf sguild.queries sguild.users
CLIENT_LIBFILES=SguilUtil.tcl dkffont.tcl email17.tcl extdata.tcl \
		sellib.tcl sancp.tcl sound.tcl guilib.tcl qrybuild.tcl \
		qrylib.tcl report.tcl stdquery.tcl whois.tcl
SENSOR_AGENTS=	pcap_agent.tcl snort_agent.tcl
SENSOR_CONFS=	pcap_agent.conf snort_agent.conf
LOG_SCRIPTS=	log_packets-daemonlogger.sh log_packets.sh
USERS=		sguil
GROUPS=		sguil

PORTDOCS=	${COMMON_DOCS:S|^doc/||}
COMMON_DOCS=	doc/CHANGES doc/FAQ doc/INSTALL doc/INSTALL.openbsd \
		doc/OPENSSL.README doc/TODO doc/UPGRADE doc/USAGE \
		doc/sguildb.dia

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
SUB_FILES=	pkg-message-client
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR+=	sguild
SUB_FILES=	pkg-message-server
.endif

.if ${PORT_OPTIONS:MSENSOR}
USE_RC_SUBR+=	pcap_agent snort_agent
SUB_FILES=	pkg-message-sensor
WITH_PCRE=	true
PORTDOCS+=	README.daemonlogger
.  if ${PORT_OPTIONS:MSANCP_SENSOR}
SENSOR_AGENTS+=	sancp_agent.tcl pcap_agent-sancp.tcl
SENSOR_CONFS+=	sancp_agent.conf sancp-indexed.conf pcap_agent-sancp.conf
USE_RC_SUBR+=	sancp_agent pcap_agent-sancp
PORTDOCS+=	README.sancp_indexed_pcap
.  endif
.  if ${PORT_OPTIONS:MPADS_SENSOR}
SENSOR_AGENTS+=	pads_agent.tcl
SENSOR_CONFS+=	pads_agent.conf
USE_RC_SUBR+=	pads_agent
.  endif
.endif

post-patch:
.if ${PORT_OPTIONS:MSERVER}
	@${REINPLACE_CMD} 's|/bin/sh|${TCLSH}|' \
		${WRKSRC}/server/sguild
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${SERVER_SGUILDIR} \
		${STAGEDIR}${PREFIX}/lib/${SERVER_SGUILDIR} \
		${STAGEDIR}${PREFIX}/share/${SERVER_SGUILDIR} \
		${STAGEDIR}${PREFIX}/share/${SERVER_SGUILDIR}/contrib
.endif
.if ${PORT_OPTIONS:MCLIENT}
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/${CLIENT_SGUILDIR} \
		${STAGEDIR}${PREFIX}/bin/${CLIENT_SGUILDIR}/lib \
		${STAGEDIR}${PREFIX}/bin/${CLIENT_SGUILDIR}/images
.endif
.if ${PORT_OPTIONS:MSENSOR}
.  for f in ${SENSOR_AGENTS}
	@${REINPLACE_CMD} 's|/bin/sh|${PREFIX}/bin/${TCLSH}|' \
		${WRKSRC}/sensor/${f}
.  endfor
.endif

do-install:
.if ${PORT_OPTIONS:MSERVER}
	(cd ${WRKSRC}/server/lib && \
		${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/lib/${SERVER_SGUILDIR})
	(cd ${WRKSRC}/server/sql_scripts && \
		${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/share/${SERVER_SGUILDIR})
	(cd ${WRKSRC}/server/contrib && \
		${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/share/${SERVER_SGUILDIR}/contrib)
	${INSTALL_SCRIPT} ${WRKSRC}/server/sguild ${STAGEDIR}${PREFIX}/bin
.  for f in ${SERVER_CONFS}
	${INSTALL_DATA} ${WRKSRC}/server/${f} \
		${STAGEDIR}${PREFIX}/etc/${SERVER_SGUILDIR}/${f}-sample
.  endfor
.endif

.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_SCRIPT} ${WRKSRC}/client/sguil.tk \
		${STAGEDIR}${PREFIX}/bin/${CLIENT_SGUILDIR}/sguil.tk
	${INSTALL_DATA} ${WRKSRC}/client/sguil.conf \
		${STAGEDIR}${PREFIX}/etc/sguil.conf-sample
	(cd ${WRKSRC}/client/lib && ${INSTALL_DATA} ${CLIENT_LIBFILES} \
		${STAGEDIR}${PREFIX}/bin/${CLIENT_SGUILDIR}/lib)
	(cd ${WRKSRC}/client/lib/images && \
		${INSTALL_DATA} sguil_logo_h.gif checked.gif unchecked.gif \
		${STAGEDIR}${PREFIX}/bin/${CLIENT_SGUILDIR}/images)
	(cd ${WRKSRC}/client/lib/tablelist5.11 && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/bin/${CLIENT_SGUILDIR}/lib/tablelist5.11)
.endif

.if ${PORT_OPTIONS:MSENSOR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/${SENSOR_SGUILDIR} \
		${STAGEDIR}${PREFIX}/etc/${SENSOR_SGUILDIR} \
		${STAGEDIR}${PREFIX}/share/${SENSOR_SGUILDIR} \
		${STAGEDIR}${PREFIX}/share/${SENSOR_SGUILDIR}/contrib \
		${STAGEDIR}${PREFIX}/share/${SENSOR_SGUILDIR}/init
	(cd ${WRKSRC}/sensor/contrib && \
		${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/share/${SENSOR_SGUILDIR}/contrib \
		"! -name ossec_agent.tcl.orig")
	(cd ${WRKSRC}/sensor/init && \
		${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/share/${SENSOR_SGUILDIR}/init)
	(cd ${WRKSRC}/sensor/ && \
		${INSTALL_SCRIPT} ${SENSOR_AGENTS} \
		${STAGEDIR}${PREFIX}/bin/${SENSOR_SGUILDIR})
	(cd ${WRKSRC}/sensor && \
		${INSTALL_SCRIPT} ${LOG_SCRIPTS} \
		${STAGEDIR}${PREFIX}/bin/${SENSOR_SGUILDIR})
.  for f in ${SENSOR_CONFS}
	${INSTALL_DATA} ${WRKSRC}/sensor/${f} \
		${STAGEDIR}${PREFIX}/etc/${SENSOR_SGUILDIR}/${f}-sample
.  endfor

.  if ${PORT_OPTIONS:MSANCP_SENSOR}
	${INSTALL_SCRIPT} ${WRKSRC}/sensor/log_packets-sancp.sh \
		${STAGEDIR}${PREFIX}/bin/${SENSOR_SGUILDIR}
	${INSTALL_DATA} ${WRKSRC}/sensor/sancp/sancp.conf \
		${STAGEDIR}${PREFIX}/etc/${SENSOR_SGUILDIR}/sancp.conf-sample
.  endif
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${COMMON_DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.  if ${PORT_OPTIONS:MSENSOR}
	${INSTALL_DATA} ${WRKSRC}/sensor/README.daemonlogger \
		${STAGEDIR}${DOCSDIR}
.    if ${PORT_OPTIONS:MSANCP_SENSOR}
	${INSTALL_DATA} ${WRKSRC}/sensor/README.sancp_indexed_pcap \
		${STAGEDIR}${DOCSDIR}
.    endif
.  endif
.endif

.include <bsd.port.mk>
