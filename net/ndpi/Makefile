# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ndpi
PORTVERSION=	2.0.2017.05.23
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	NTOP-maintained superset of the popular OpenDPI library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

CONFIGURE_ARGS=	--with-pic
CPPFLAGS+=	-I${LOCALBASE}/include/json-c
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-ljson-c
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	 	autoreconf compiler:c++11-lang libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	ntop
GH_PROJECT=	nDPI
GH_TAGNAME=	3cfcc05

PLIST_SUB=	MAJOR_VER=${PORTVERSION:C/([[:digit:]])+\.([[:digit:]])+.*/\1.\2/}.0

.include <bsd.port.mk>
