# Created by: Dima Dorfman <dd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	http_ping
PORTVERSION=	20050629
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://www.acme.com/software/${PORTNAME}/
DISTNAME=	${PORTNAME}_29jun2005

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Measure HTTP Latency

USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		http_ping.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/http_ping

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/http_ping ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/http_ping.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
