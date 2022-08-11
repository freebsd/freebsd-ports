PORTNAME=	netpipes
PORTVERSION=	4.2
CATEGORIES=	net
MASTER_SITES=	LOCAL/kris
DISTNAME=	netpipes-4.2-export

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	Group of shell utilities to connect programs to sockets

CONFLICTS=	timelimit

NO_WRKSUBDIR=	yes

do-install:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} STAGEDIR=${STAGEDIR} install

.include <bsd.port.mk>
