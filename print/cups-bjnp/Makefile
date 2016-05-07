# $FreeBSD$

PORTNAME=	cups-bjnp
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	CUPS backend for Canon USB over IP protocol

LIB_DEPENDS=	libcups.so:print/cups

GNU_CONFIGURE=	yes
# Just to avoid a tautological pointer compare in bjnp-commands.c:187
CONFIGURE_ARGS+=	--disable-Werror
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
