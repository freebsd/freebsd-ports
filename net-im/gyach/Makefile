# New ports collection makefile for:	gyach
# Date created:				08 November 2003
# Whom:					Aaron Landwehr <aaron@snaphat.com>
#
# $FreeBSD$
#

PORTNAME=	gyach
PORTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www4.infi.net/~cpinkham/gyach/code/

MAINTAINER?=	aaron@snaphat.com
COMMENT=	Gyach is a GTK+ based Yahoo! Chat client

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_FLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
USE_GNOME=	gtk20
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.include <bsd.port.post.mk>
