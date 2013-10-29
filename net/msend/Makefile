# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	msend
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	markp

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Client and server for the RFC1312 message protocol

USE_RC_SUBR=	mesgd
USE_AUTOTOOLS=	aclocal autoheader autoconf automake
AUTOMAKE_ARGS+=	--add-missing
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
