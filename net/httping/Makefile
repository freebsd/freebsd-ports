# New ports collection makefile for:	httping
# Date created:				26 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	httping
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A ping-like tool for HTTP requests

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"
LDFLAGS+=	-lssl -lcrypto

SRC=		http io str error utils main tcp mssl res
PLIST_FILES=	bin/httping

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} -c ${WRKSRC}/${f}.c -o ${WRKSRC}/${f}.o
.endfor
	${CC} ${CFLAGS} ${LDFLAGS} ${SRC:C/(.*)/${WRKSRC}\/\1.o/} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
