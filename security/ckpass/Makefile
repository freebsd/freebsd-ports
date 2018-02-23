# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ckpass
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based password database client

LICENSE=	GPLv3

LIB_DEPENDS=	libkpass.so:security/libkpass

USES=		ncurses
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/ckpass

.include <bsd.port.mk>
