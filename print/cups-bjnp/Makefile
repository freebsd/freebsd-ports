# $FreeBSD$

PORTNAME=	cups-bjnp
PORTVERSION=	1.2.2
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	CUPS backend for Canon USB over IP protocol

LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
BUILD_DEPENDS=	${LOCALBASE}/libexec/cups/backend:${PORTSDIR}/print/cups-base

PORTSCOUT=	ignore:1.9.*

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
