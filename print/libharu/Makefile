# ex:ts=8
# Ports collection makefile for:	libharu
# Date created:			Jun 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libharu
PORTVERSION=	2.2.1
CATEGORIES=	print
MASTER_SITES=	http://libharu.org/files/

MAINTAINER=	kimelto@gmail.com
COMMENT=	Haru Free PDF Library

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-png=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

.include <bsd.port.mk>
