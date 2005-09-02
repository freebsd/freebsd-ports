# New ports collection makefile for:	micro_proxy
# Date created:				 2 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	micro_proxy
PORTVERSION=	20021030
CATEGORIES=	net
MASTER_SITES=	http://www.acme.com/software/micro_proxy/
DISTNAME=	${PORTNAME}_30oct2002

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A really small HTTP/HTTPS proxy

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	libexec/micro_proxy
MAN8=		micro_proxy.8

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}.o
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.o -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${PKGMESSAGE}

.include <bsd.port.mk>
