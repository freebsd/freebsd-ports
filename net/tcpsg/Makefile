PORTNAME=	tcpsg
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple TCP port forwarder
WWW=		https://tcpsg.sourceforge.net/

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
