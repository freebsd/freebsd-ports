# New ports collection makefile for:	cups-bjnp
# Date created:				15 May 2009
# Whom:					shurd@sasktel.net
#
# $FreeBSD$
#

PORTNAME=	cups-bjnp
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	shurd@sasktel.net
COMMENT=	CUPS backend for Canon USB over IP protocol

LIB_DEPENDS=	cupsimage.2:${PORTSDIR}/print/cups-base

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS+="-I${LOCALBASE}/include" CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" LIBS="-lcompat"

.include <bsd.port.mk>
