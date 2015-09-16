# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	msend
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/markp

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Client and server for the RFC1312 message protocol

USES=		autoreconf readline
USE_RC_SUBR=	mesgd
GNU_CONFIGURE=	yes
CFLAGS+=	-DUSE_READLINE -DNO_GETDTABLESIZE -DNEW_HEADERS

PLIST_FILES=	bin/msend \
		man/man1/msend.1.gz \
		man/man8/mesgd.8.gz \
		sbin/mesgd

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
CFLAGS+=	-DUSE_UTMPX
.endif

.include <bsd.port.post.mk>
