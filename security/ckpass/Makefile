# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	ckpass
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Ncurses based password database client

LICENSE=	GPLv3

LIB_DEPENDS=	kpass:${PORTSDIR}/security/libkpass

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/ckpass

.include <bsd.port.mk>
