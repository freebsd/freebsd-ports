# New ports collection makefile for:	datapipe
# Date created:		04 January 2000
# Whom:			Daniel Baker <dbaker@FreeBSD.org> <dbaker@cuckoo.com>
#
# $FreeBSD$
#

PORTNAME=	datapipe
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/unsupported/ \
		http://http.distributed.net/pub/dcti/unsupported/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Bind a local port and connect it to a remote socket

PLIST_FILES=	bin/datapipe

OPTIONS=	REUSEADDR    "Reuse the listening socket address"  on \
		NOFORK       "Do not fork and background" off

.include <bsd.port.pre.mk>

.if defined(WITH_REUSEADDR)
CFLAGS+=	-DDATAPIPE_REUSEADDR
.endif

.if defined(WITH_NOFORK)
CFLAGS+=	-DDATAPIPE_NOFORK
PKGNAMESUFFIX+=-nofork
.endif

do-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/${DISTNAME}/datapipe ${WRKDIR}/${DISTNAME}/datapipe.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datapipe ${PREFIX}/bin

.include <bsd.port.post.mk>
