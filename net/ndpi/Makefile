# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ndpi
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	NTOP-maintained superset of the popular OpenDPI library

LICENSE=	GPLv3

LIB_DEPENDS=	libjson-c.so:devel/json-c

CONFIGURE_ARGS=	--with-pic
CPPFLAGS+=	-I${LOCALBASE}/include/json-c
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-ljson-c
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	 	alias autoreconf compiler:c++11-lang libtool pathfix pkgconfig tar:tgz
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	ntop
GH_PROJECT=	nDPI
GH_TAGNAME=	6fb81f1

PLIST_SUB=	MAJOR_VER=${PORTVERSION}.0

post-patch:
	${REINPLACE_CMD} 's|$$(libdir)|$$(libdir)data|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
