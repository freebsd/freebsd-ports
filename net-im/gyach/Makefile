# Created by: Aaron Landwehr <aaron@snaphat.com>
# $FreeBSD$

PORTNAME=	gyach
PORTVERSION=	0.9.8
PORTREVISION=	9
CATEGORIES=	net-im
MASTER_SITES=	http://www4.infi.net/~cpinkham/gyach/code/

MAINTAINER?=	aaron@snaphat.com
COMMENT=	Gyach is a GTK+ based Yahoo! Chat client

GNU_CONFIGURE=	yes
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
USE_GNOME=	gtk20

NO_STAGE=	yes

BROKEN=		Does not compile

.include <bsd.port.mk>
