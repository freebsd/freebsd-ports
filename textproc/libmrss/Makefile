# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmrss
PORTVERSION=	0.19.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.autistici.org/bakunin/libmrss/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	C library for parsing, writing, and creating RSS

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		nxml:${PORTSDIR}/textproc/libnxml

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
USE_GNOME=	gnomehack

.include <bsd.port.mk>
