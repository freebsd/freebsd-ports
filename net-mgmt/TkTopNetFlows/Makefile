# Created by: vfom@narod.ru
# $FreeBSD$

PORTNAME=	TkTopNetFlows
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	http://vfom.narod.ru/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI tool for NetFlow data visualisation

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS+=	libBLT25.so:${PORTSDIR}/x11-toolkits/blt \
		libTktable2.10.so:${PORTSDIR}/x11-toolkits/tktable
RUN_DEPENDS=	flowdumper:${PORTSDIR}/net-mgmt/p5-Cflow

NO_BUILD=	yes
USES=		perl5 tk:85
PORTDOCS=	*
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/bin/wish8.4|${WISH}|' \
	    ${WRKSRC}/TkTopNetFlows.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlows.tcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlowsHist.tcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/flow_Server.pl ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/flow_Server.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/view_definitions.pl.example ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${PORTVERSION}
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlows_lib.tcl ${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${PORTVERSION}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
