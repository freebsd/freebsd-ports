# New ports collection makefile for:	flowviewer
# Date created:			Oct 15, 2006
# Whom:				Alex Samorukov, samm@os2.kiev.ua
#
# $FreeBSD$

PORTNAME=	flowviewer
PORTVERSION=	3.3.1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ensight.eos.nasa.gov/FlowViewer/
DISTNAME=	FlowViewer_${DISTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Web-based user interface for the flow-tools NetFlow data

RUN_DEPENDS=	p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph \
		flow-cat:${PORTSDIR}/net-mgmt/flow-tools

.ifndef WITHOUT_WWWDIR
FLOWVIEWERDIR?=	${PREFIX}/www/flowviewer
.else
FLOWVIEWERDIR?=	${PREFIX}/flowviewer
.endif

PLIST_SUB+=	FLOWVIEWERDIR="${FLOWVIEWERDIR:S,^${PREFIX}/,,}"
SUB_LIST+=	"FLOWVIEWERDIR=${FLOWVIEWERDIR}" \
		"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

USE_PERL5=	yes
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
	@${MKDIR} ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowGrapher.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowGrapher_Main.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowGrapher_Relay.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowGrapher_Sort.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowTracker.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowTracker_Dumper.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowTracker_Relay.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowViewer.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowViewer_Main.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowViewer_Relay.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowViewer_Save.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowTracker_Group.cgi ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowViewer_Utilities.pm ${FLOWVIEWERDIR}
	@${INSTALL_DATA} ${WRKSRC}/FlowViewer_Configuration.pm ${FLOWVIEWERDIR}/FlowViewer_Configuration.pm.dist
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowTracker_Collector ${FLOWVIEWERDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/FlowTracker_Grapher ${FLOWVIEWERDIR}
	@${INSTALL_DATA} ${WRKSRC}/FlowGrapher_Colors ${FLOWVIEWERDIR}
	@${INSTALL_DATA} ${WRKSRC}/FlowGrapher.png ${FLOWVIEWERDIR}
	@${INSTALL_DATA} ${WRKSRC}/FlowTracker.png ${FLOWVIEWERDIR}
	@${INSTALL_DATA} ${WRKSRC}/FlowViewer.png ${FLOWVIEWERDIR}
	@${MKDIR} ${FLOWVIEWERDIR}/tmp ${FLOWVIEWERDIR}/reports \
	${FLOWVIEWERDIR}/graphs ${FLOWVIEWERDIR}/tracker
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${FLOWVIEWERDIR}/tmp \
	${FLOWVIEWERDIR}/reports ${FLOWVIEWERDIR}/graphs \
	${FLOWVIEWERDIR}/tracker

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
