# Created by: Alex Samorukov, samm@freebsd.org
# $FreeBSD$

PORTNAME=	flowviewer
PORTVERSION=	4.5
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	FlowViewer_${DISTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	samm@freebsd.org
COMMENT=	Web-based user interface for the flow-tools NetFlow data

RUN_DEPENDS=	p5-GD-Graph>=0:graphics/p5-GD-Graph \
		rrdtool:databases/rrdtool \
		rwptoflow:security/silktools

OPTIONS_DEFINE=	DOCS

FLOWVIEWERDIR?=	${PREFIX}/www/flowviewer

FLOWVIEWERSCRIPTS=	FV.cgi FV_Relay.cgi FlowGrapher.cgi FlowGrapher_Analyze.cgi \
		FlowGrapher_Main.cgi FlowGrapher_Replay.cgi FlowGrapher_Sort.cgi \
		FlowMonitor.cgi FlowMonitor_Dashboard.cgi FlowMonitor_Display.cgi \
		FlowMonitor_DisplayPublic.cgi FlowMonitor_Dumper.cgi \
		FlowMonitor_Group.cgi FlowMonitor_Main.cgi FlowMonitor_Management.cgi \
		FlowMonitor_Replay.cgi FlowViewer.cgi FlowViewer_Main.cgi \
		FlowViewer_Replay.cgi FlowViewer_Save.cgi FlowViewer_SaveManage.cgi \
		FlowViewer_Sort.cgi FlowViewer_UI.pm FlowViewer_Utilities.pm \
		FlowMonitor_Collector FlowMonitor_Grapher \
		FlowMonitor_Recreate FlowMonitor_Thumbnail FlowViewer_CleanASCache \
		FlowViewer_CleanFiles FlowViewer_CleanHostCache FlowViewer_CleanSiLK
FLOWVIEWERDATA=	FG_button.png FM_button.png FV_button.png FlowViewer.css
SHEBANG_TOOLS=	tools/analyze_flowmonitor_debug tools/analyze_netflow_packets \
		tools/convert_pre40_filters tools/create_ports_file tools/date_to_epoch_gm \
		tools/date_to_epoch_local tools/epoch_to_date_gm tools/epoch_to_date_local \
		tools/flowmonitor_archive_restore tools/flowmonitor_grapher_nonlazy \
		tools/flowmonitor_grapher_recent tools/performance_check tools/resize_rrdtools
FLOWVIEWERTOOLS=	${SHEBANG_TOOLS} \
		tools/flowcapture_restart tools/flowmonitor_restart \
		tools/flow-capture-table.conf tools/rsync_monitors tools/rwflowpack_start \
		tools/rsync_htmls tools/rsync_flows
FLOWVIEWERCONFIGS=	FlowViewer_Configuration.pm \
		FlowGrapher_Colors FlowGrapher_Ports \
		NamedInterfaces_Devices NamedInterfaces_Exporters \
		dscan.suppress.dst dscan.suppress.src

PLIST_SUB+=	FLOWVIEWERDIR="${FLOWVIEWERDIR}" \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
SUB_LIST+=	"FLOWVIEWERDIR=${FLOWVIEWERDIR}" \
		"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

USES=		perl5 shebangfix
SHEBANG_FILES=	${FLOWVIEWERSCRIPTS} ${SHEBANG_TOOLS} FlowViewer_Configuration.pm
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
	${MKDIR} ${STAGEDIR}${FLOWVIEWERDIR}/tmp ${STAGEDIR}${FLOWVIEWERDIR}/reports ${STAGEDIR}${FLOWVIEWERDIR}/graphs \
	${STAGEDIR}${FLOWVIEWERDIR}/monitor ${STAGEDIR}${FLOWVIEWERDIR}/working ${STAGEDIR}${FLOWVIEWERDIR}/saves \
	${STAGEDIR}${FLOWVIEWERDIR}/names ${STAGEDIR}${FLOWVIEWERDIR}/ipsets ${STAGEDIR}${FLOWVIEWERDIR}/filters \
	${STAGEDIR}${FLOWVIEWERDIR}/rrdtools ${STAGEDIR}${FLOWVIEWERDIR}/FlowViewer_Dashboard
.for i in ${FLOWVIEWERCONFIGS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${FLOWVIEWERDIR}/${i}.sample
.endfor
.for i in ${FLOWVIEWERSCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${FLOWVIEWERDIR}
.endfor
.for i in ${FLOWVIEWERTOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${FLOWVIEWERDIR}/tools
.endfor
.for i in ${FLOWVIEWERDATA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${FLOWVIEWERDIR}/reports
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
