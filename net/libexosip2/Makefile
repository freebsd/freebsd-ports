# Created by: Muhammad Moinur Rahman <bd_subzero@yahoo.com>

PORTNAME=	libeXosip2
PORTVERSION=	5.3.0
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/exosip
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GPL library that extends the capability of the oSIP library

LICENSE=	GPLv2

LIB_DEPENDS=	libosip2.so:net/libosip2

USES=		libtool ssl
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libeXosip2-legacy

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SHLIB_VER=	15

PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
