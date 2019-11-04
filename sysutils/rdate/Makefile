# Created by: cracauer@cons.org "Martin Cracauer"
# $FreeBSD$

PORTNAME=	rdate
PORTVERSION=	20150501
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/rdate/ \
		LOCAL/johans

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sets the clock of the local host to the time of another host

CFLAGS+=	-DNO_UTIL -D__dead= -D'SA_LEN(x)=(x)->sa_len'
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	sbin/rdate man/man8/${PORTNAME}.8.gz

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,/right,,' ${WRKSRC}/rdate.8
.if ${OPSYS} == DragonFly
	${REINPLACE_CMD} -e '/^SRCS/s/$$/ reallocarray.c/' ${WRKSRC}/Makefile
	${ECHO} 'void *reallocarray(void *optr, size_t nmemb, size_t size);' \
		>> ${WRKSRC}/ntpleaps.h
	${CP} ${FILESDIR}/*.c ${WRKSRC}/
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdate ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/rdate.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.post.mk>
