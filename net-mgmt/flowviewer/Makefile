# Created by: Alex Samorukov, samm@os2.kiev.ua
# $FreeBSD$

PORTNAME=	flowviewer
PORTVERSION=	4.5
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	FlowViewer_${DISTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Web-based user interface for the flow-tools NetFlow data

RUN_DEPENDS=	p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		rrdtool:${PORTSDIR}/databases/rrdtool

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	NETFLOWv
OPTIONS_SINGLE_NETFLOWv=	NETFLOWv5 NETFLOWv9
OPTIONS_DEFAULT=	NETFLOWv5
NETFLOWv5_DESC=	Support for NETFLOWv5
NETFLOWv9_DESC=	Support for IPFIX/NETFLOWv9
NETFLOWv5_RUN_DEPENDS=	flow-cat:${PORTSDIR}/net-mgmt/flow-tools-ng
NETFLOWv9_RUN_DEPENDS=	rwptoflow:${PORTSDIR}/security/silktools

FLOWVIEWERDIR?=	${PREFIX}/www/flowviewer

PLIST_SCRIPT=	FV.cgi FV_Relay.cgi FlowGrapher.cgi FlowGrapher_Main.cgi \
		FlowGrapher_Replay.cgi FlowGrapher_Sort.cgi \
		FlowMonitor.cgi FlowMonitor_Dashboard.cgi FlowMonitor_Display.cgi \
		FlowMonitor_DisplayPublic.cgi FlowMonitor_Dumper.cgi \
		FlowMonitor_Group.cgi FlowMonitor_Main.cgi FlowMonitor_Management.cgi \
		FlowMonitor_Replay.cgi FlowViewer.cgi dscan.suppress.dst dscan.suppress.src \
		FlowViewer_Main.cgi FlowViewer_Replay.cgi \
		FlowViewer_Save.cgi FlowViewer_SaveManage.cgi FlowViewer_Sort.cgi \
		FlowViewer_UI.pm FlowViewer_Utilities.pm FlowGrapher_Colors \
		FlowMonitor_Collector FlowMonitor_Grapher \
		FlowMonitor_Recreate FlowMonitor_Thumbnail FlowViewer_CleanASCache \
		FlowViewer_CleanFiles FlowViewer_CleanHostCache FlowViewer_CleanSiLK
PLIST_DATA=	FG_button.png FM_button.png FV_button.png FlowViewer.css
PLIST_TOOLS=	flowcapture_restart resize_rrdtools flowmonitor_grapher_nonlazy \
		date_to_epoch_gm performance_check flowmonitor_restart \
		convert_pre40_filters analyze_flowmonitor_debug flowmonitor_grapher_recent \
		flow-capture-table.conf rsync_monitors epoch_to_date_local rwflowpack_start \
		epoch_to_date_gm rsync_htmls flowmonitor_archive_restore \
		date_to_epoch_local analyze_netflow_packets rsync_flows

PLIST_SUB+=	FLOWVIEWERDIR="${FLOWVIEWERDIR}" \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
SUB_LIST+=	"FLOWVIEWERDIR=${FLOWVIEWERDIR}" \
		"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

USES=		perl5
NO_BUILD=	yes

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/FlowViewer_Configuration.pm
	@${REINPLACE_CMD} -E \
		-e "s|%%FLOWVIEWERDIR%%|${FLOWVIEWERDIR}|" \
		${WRKSRC}/FlowViewer_Configuration.pm

do-install:
	${MKDIR} ${STAGEDIR}${FLOWVIEWERDIR}
	${MKDIR} ${STAGEDIR}${FLOWVIEWERDIR}/tools
	${INSTALL_DATA} ${WRKSRC}/FlowViewer_Configuration.pm ${STAGEDIR}${FLOWVIEWERDIR}/FlowViewer_Configuration.pm.sample
	${INSTALL_DATA} ${WRKSRC}/NamedInterfaces_Devices ${STAGEDIR}${FLOWVIEWERDIR}/NamedInterfaces_Devices.sample
	${INSTALL_DATA} ${WRKSRC}/NamedInterfaces_Exporters ${STAGEDIR}${FLOWVIEWERDIR}/NamedInterfaces_Exporters.sample
	${MKDIR} ${STAGEDIR}${FLOWVIEWERDIR}/tmp ${STAGEDIR}${FLOWVIEWERDIR}/reports ${STAGEDIR}${FLOWVIEWERDIR}/graphs \
	${STAGEDIR}${FLOWVIEWERDIR}/monitor ${STAGEDIR}${FLOWVIEWERDIR}/working ${STAGEDIR}${FLOWVIEWERDIR}/saves \
	${STAGEDIR}${FLOWVIEWERDIR}/names ${STAGEDIR}${FLOWVIEWERDIR}/ipsets ${STAGEDIR}${FLOWVIEWERDIR}/filters \
	${STAGEDIR}${FLOWVIEWERDIR}/rrdtools ${STAGEDIR}${FLOWVIEWERDIR}/FlowViewer_Dashboard
.for i in ${PLIST_SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${FLOWVIEWERDIR}
.endfor
.for i in ${PLIST_TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/${i} ${STAGEDIR}${FLOWVIEWERDIR}/tools
.endfor
.for i in ${PLIST_DATA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${FLOWVIEWERDIR}/reports
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
