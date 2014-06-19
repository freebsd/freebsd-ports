# Created by: cracauer@cons.org "Martin Cracauer"
# $FreeBSD$

PORTNAME=	rdate
PORTVERSION=	20140220
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	johans

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Sets the clock of the local host to the time of another host

CFLAGS+=	-DNO_UTIL -D__dead= -D'SA_LEN(x)=(x)->sa_len'
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	sbin/rdate man/man8/${PORTNAME}.8.gz

post-patch:
	${REINPLACE_CMD} -e 's,/right,,' ${WRKSRC}/rdate.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdate ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/rdate.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
