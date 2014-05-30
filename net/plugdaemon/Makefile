# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	plugdaemon
PORTVERSION=	2.5.5
CATEGORIES=	net
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Plug proxy daemon, forwards TCP/IP connections

do-install:

	${INSTALL_MAN} ${WRKSRC}/plug.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/plug ${STAGEDIR}${PREFIX}/sbin
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/plug

.include <bsd.port.mk>
