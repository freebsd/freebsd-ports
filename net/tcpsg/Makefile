PORTNAME=	tcpsg
PORTVERSION=	0.0.2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Simple TCP port forwarder

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/tcpsg.c
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/tcpsg.conf ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/tcpsg.ctl ${STAGEDIR}${DOCSDIR}/tcpsg.ctl

.include <bsd.port.mk>
