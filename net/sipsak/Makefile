# New ports collection makefile for:	sipsak
# Date created:		2003-06-30
# Whom:			jesusr
#
# $FreeBSD$
#

PORTNAME=	sipsak
PORTVERSION=	0.8.1
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/sipsak/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jesusr@FreeBSD.org
COMMENT=	Small command line tool for SIP testing

MAN1=		sipsak.1

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -c md5.c && \
	${CC} ${CFLAGS} -c sipsak.c && \
	${CC} ${LDFLAGS} -o sipsak md5.o sipsak.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sipsak ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sipsak.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
