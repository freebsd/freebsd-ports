# New ports collection makefile for:	httping
# Date created:				26 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	httping
PORTVERSION=	1.0.8
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A ping-like tool for HTTP requests

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"
LDFLAGS+=	-lssl -lcrypto

SRC=		http io str error utils main tcp mssl res
MAN1=		httping.1
PLIST_FILES=	bin/httping

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} -c ${WRKSRC}/${f}.c -o ${WRKSRC}/${f}.o
.endfor
	${CC} ${LDFLAGS} ${SRC:C/(.*)/${WRKSRC}\/\1.o/} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
