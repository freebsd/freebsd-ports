# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	micro_proxy
PORTVERSION=	20140814
CATEGORIES=	net
MASTER_SITES=	http://www.acme.com/software/micro_proxy/ \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_14Aug2014

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Really small HTTP/HTTPS proxy

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	libexec/micro_proxy man/man8/micro_proxy.8.gz
SUB_FILES=	pkg-message

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}.o
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.o -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
