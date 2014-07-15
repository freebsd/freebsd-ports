# Created by: Muhammad Moinur Rahman <bd_subzero@yahoo.com>
# $FreeBSD$

PORTNAME=	libeXosip2
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/exosip

MAINTAINER=	5u623l20@gmail.com
COMMENT=	GPL library that extends the capability of the oSIP library

LICENSE=	GPLv2

LIB_DEPENDS=	libosip2.so:${PORTSDIR}/net/libosip2

CONFLICTS_INSTALL=	libeXosip2-legacy-[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes
SHLIB_VER=	11

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
