# New ports collection makefile for:	TkTopNetFlows
# Date created:				2004 Apr 14
# Whom:					vfom@narod.ru
#
# $FreeBSD$
#

PORTNAME=	TkTopNetFlows
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://vfom.narod.ru/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI tool for NetFlow data visualisation

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/lib/libBLT24.so.3:${PORTSDIR}/x11-toolkits/blt \
		${LOCALBASE}/lib/Tktable2.10/libTktable2.10.so:${PORTSDIR}/x11-toolkits/tktable \
		${SITE_PERL}/${PERL_ARCH}/Cflow.pm:${PORTSDIR}/net-mgmt/p5-Cflow

NO_MTREE=	yes
NO_BUILD=	yes
USE_PERL5=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_SUB=	PORTVERSION=${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlows.tcl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlowsHist.tcl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/flow_Server.pl ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/flow_Server.sh ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/view_definitions.pl.example ${PREFIX}/etc
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}-${PORTVERSION}
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlows_lib.tcl ${PREFIX}/lib/${PORTNAME}-${PORTVERSION}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
