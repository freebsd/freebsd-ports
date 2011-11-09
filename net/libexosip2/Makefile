# New ports collection makefile for:	libeXosip2
# Date created:				12 April 2006
# Whom:					Muhammad Moinur Rahman <bd_subzero@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	libeXosip2
PORTVERSION=	3.3.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/exosip

MAINTAINER=	bd_subzero@yahoo.com
COMMENT=	GPL library that extends the capability of the oSIP library

LIB_DEPENDS=	osip2:${PORTSDIR}/net/libosip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-tools --disable-debug --disable-trace
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/HAVE_OPENSSL/d' ${WRKSRC}/config.h.in

.include <bsd.port.mk>
