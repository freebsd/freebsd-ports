# Created by: proot@iaces.com
# $FreeBSD$

PORTNAME=	nettest
PORTVERSION=	92.11.09
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cray.com/src/nettest/
DISTNAME=	nettest.92.11.09

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performs client and server functions for timing data throughput

BROKEN=		unfetchable

NO_WRKSUBDIR=	yes
USES=		tar:Z

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nettest ${STAGEDIR}${PREFIX}/bin/nettest
	${INSTALL_PROGRAM} ${WRKSRC}/nettestd ${STAGEDIR}${PREFIX}/bin/nettestd
	${INSTALL_MAN} ${WRKSRC}/nettest.8 ${STAGEDIR}${PREFIX}/man/man8/nettest.8

.include <bsd.port.mk>
