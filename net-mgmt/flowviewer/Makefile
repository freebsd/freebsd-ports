# Created by: Alex Samorukov, samm@os2.kiev.ua
# $FreeBSD$

PORTNAME=	flowviewer
PORTVERSION=	4.2.2
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

FLOWVIEWERDIR?=	${STAGEDIR}${PREFIX}/www/flowviewer

PLIST_SCRIPT=	FV.cgi FV_Relay.cgi FlowGrapher.cgi FlowGrapher_Main.cgi \
		FlowGrapher_Relay.cgi FlowGrapher_Replay.cgi FlowGrapher_Sort.cgi \
		FlowTracker.cgi FlowTracker_Dashboard.cgi FlowTracker_Display.cgi \
		FlowTracker_DisplayPublic.cgi FlowTracker_Dumper.cgi \
		FlowTracker_Group.cgi FlowTracker_Main.cgi FlowTracker_Management.cgi \
		FlowTracker_Relay.cgi FlowTracker_Replay.cgi FlowViewer.cgi \
		FlowViewer_Main.cgi FlowViewer_Relay.cgi FlowViewer_Replay.cgi \
		FlowViewer_Save.cgi FlowViewer_SaveManage.cgi FlowViewer_Sort.cgi \
		FlowViewer_UI.pm FlowViewer_Utilities.pm FlowGrapher_Colors \
		FlowTracker_AltDashboard FlowTracker_Collector FlowTracker_Grapher \
		FlowTracker_Recreate FlowTracker_Thumbnail FlowViewer_CleanASCache \
		FlowViewer_CleanFiles FlowViewer_CleanHostCache FlowViewer_CleanSiLK \
		NamedInterfaces_Devices NamedInterfaces_Exporters
PLIST_DATA=	FG_button.png FT_button.png FV_button.png FlowViewer.css
PLIST_TOOLS=	flowcapture_restart resize_rrdtools flowtracker_grapher_nonlazy \
		date_to_epoch_gm performance_check edc_rwflowappend flowtracker_restart \
		convert_pre40_filters analyze_flowtracker_debug flowtracker_grapher_recent \
		flow-capture-table.conf rsync_trackings epoch_to_date_local rwflowpack_start \
		edc_rwreceiver epoch_to_date_gm rsync_htmls flowtracker_archive_restore \
		date_to_epoch_local analyze_netflow_packets rsync_flows copy_netflow_jpl

PLIST_SUB+=	FLOWVIEWERDIR="${FLOWVIEWERDIR:S,^${STAGEDIR}${PREFIX}/,,}"
SUB_LIST+=	"FLOWVIEWERDIR=${FLOWVIEWERDIR}" \
		"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

USES=		perl5
NO_BUILD=	yes

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>
post-patch:
	@${REINPLACE_CMD} -E \
		-e "s|%%PREFIX%%|${STAGEDIR}${PREFIX}|" \
		${WRKSRC}/FlowViewer_Configuration.pm
	@${REINPLACE_CMD} -E \
		-e "s|%%FLOWVIEWERDIR%%|${FLOWVIEWERDIR}|" \
		${WRKSRC}/FlowViewer_Configuration.pm

do-install:
	${MKDIR} ${FLOWVIEWERDIR}
	${MKDIR} ${FLOWVIEWERDIR}/tools
	${INSTALL_DATA} ${WRKSRC}/FlowViewer_Configuration.pm ${FLOWVIEWERDIR}/FlowViewer_Configuration.pm.dist
	${MKDIR} ${FLOWVIEWERDIR}/tmp ${FLOWVIEWERDIR}/reports \
	${FLOWVIEWERDIR}/graphs ${FLOWVIEWERDIR}/tracker ${FLOWVIEWERDIR}/working \
	${FLOWVIEWERDIR}/saves ${FLOWVIEWERDIR}/names ${FLOWVIEWERDIR}/filters \
	${FLOWVIEWERDIR}/rrdtools ${FLOWVIEWERDIR}/FlowViewer_Dashboard
	${CHOWN} ${WWWOWN}:${WWWGRP} ${FLOWVIEWERDIR}/tmp \
	${FLOWVIEWERDIR}/reports ${FLOWVIEWERDIR}/graphs \
	${FLOWVIEWERDIR}/tracker ${FLOWVIEWERDIR}/working ${FLOWVIEWERDIR}/saves \
	${FLOWVIEWERDIR}/names ${FLOWVIEWERDIR}/filters ${FLOWVIEWERDIR}/rrdtools \
	${FLOWVIEWERDIR}/FlowViewer_Dashboard ${FLOWVIEWERDIR}/tools
.for i in ${PLIST_SCRIPT}
	@${INSTALL_SCRIPT} ${WRKSRC}/${i} ${FLOWVIEWERDIR}
.endfor
.for i in ${PLIST_TOOLS}
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/${i} ${FLOWVIEWERDIR}/tools
.endfor
.for i in ${PLIST_DATA}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${FLOWVIEWERDIR}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
