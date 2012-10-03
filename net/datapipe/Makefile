# Created by: Daniel Baker <dbaker@FreeBSD.org> <dbaker@cuckoo.com>
# $FreeBSD$

PORTNAME=	datapipe
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.distributed.net/pub/dcti/unsupported/ \
		http://http.distributed.net/pub/dcti/unsupported/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Bind a local port and connect it to a remote socket

PLIST_FILES=	bin/datapipe

OPTIONS_DEFINE=	REUSEADDR NOFORK
OPTIONS_DEFAULT=	REUSEADDR
REUSEADDR_DESC=	Reuse the listening socket address
NOFORK_DESC=	Do not fork and background

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MREUSEADDR}
CFLAGS+=	-DDATAPIPE_REUSEADDR
.endif

.if ${PORT_OPTIONS:MNOFORK}
CFLAGS+=	-DDATAPIPE_NOFORK
PKGNAMESUFFIX+=-nofork
.endif

do-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/${DISTNAME}/datapipe ${WRKDIR}/${DISTNAME}/datapipe.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/datapipe ${PREFIX}/bin

.include <bsd.port.post.mk>
