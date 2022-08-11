PORTNAME=	TkTopNetFlows
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	net-mgmt
MASTER_SITES=	http://vfom.narod.ru/download/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	GUI tool for NetFlow data visualisation

# LICENSE - zero indication within source, need to contact author

LIB_DEPENDS=	libBLT25.so:x11-toolkits/blt \
		libTktable2.10.so:x11-toolkits/tktable
RUN_DEPENDS=	flowdumper:net-mgmt/p5-Cflow

USES=		perl5 shebangfix tk:86
SHEBANG_FILES=	flow_Server.pl view_definitions.pl.example
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/wish8.4|${WISH}|' \
		${WRKSRC}/TkTopNetFlows.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlows.tcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlowsHist.tcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/flow_Server.pl ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/flow_Server.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/view_definitions.pl.example ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${PORTVERSION}
	${INSTALL_SCRIPT} ${WRKSRC}/TkTopNetFlows_lib.tcl ${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${PORTVERSION}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
