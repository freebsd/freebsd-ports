# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ndpi
PORTVERSION=	1.5.1
CATEGORIES=	net
MASTER_SITES=	SF/ntop/nDPI
DISTNAME=	libndpi-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	NTOP-maintained superset of the popular OpenDPI library

LICENSE=	GPLv3

LIB_DEPENDS=	libjson-c.so:${PORTSDIR}/devel/json-c

CONFIGURE_ARGS=	--with-pic
CPPFLAGS+=	-I${LOCALBASE}/include/json-c
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-ljson-c
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	 	libtool pathfix pkgconfig compiler:c++11-lang
WRKSRC=		${WRKDIR}/libndpi-${PORTVERSION}
INSTALL_TARGET=	install-strip

PLIST_SUB=	MAJOR_VER=${PORTVERSION}

.include <bsd.port.mk>
