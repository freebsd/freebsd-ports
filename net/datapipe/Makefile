# New ports collection makefile for:	datapipe
# Date created:		04 January 2000
# Whom:			Daniel Baker <dbaker@FreeBSD.org> <dbaker@cuckoo.com>
#
# $FreeBSD$
#

PORTNAME=	datapipe
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/unsupported/ \
		http://http.distributed.net/pub/dcti/unsupported/

MAINTAINER=	dbaker@FreeBSD.org
COMMENT=	A simple program to bind a local port and connect it to a remote socket

PLIST_FILES=	bin/datapipe

do-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/${DISTNAME}/datapipe ${WRKDIR}/${DISTNAME}/datapipe.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datapipe ${PREFIX}/bin

.include <bsd.port.mk>
