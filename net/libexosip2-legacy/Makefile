# Created by: Muhammad Moinur Rahman <bd_subzero@yahoo.com>
# $FreeBSD$

PORTNAME=	libeXosip2
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/exosip
PKGNAMESUFFIX=	-legacy

MAINTAINER=	5u623l20@gmail.com
COMMENT=	GPL library that extends the capability of the oSIP library

LICENSE=	GPLv2

LIB_DEPENDS=	libosip2.so:${PORTSDIR}/net/libosip

CONFLICTS_INSTALL=	libeXosip2-[0-9]*

DEPRECATED=	Superseded by net/libexosip2
EXPIRATION_DATE=2014-08-31

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-tools --disable-debug --disable-trace
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/HAVE_OPENSSL/d' ${WRKSRC}/config.h.in

.include <bsd.port.mk>
