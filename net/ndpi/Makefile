# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ndpi
PORTVERSION=	2.2.2018.01.31
CATEGORIES=	net

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	NTOP-maintained superset of the popular OpenDPI library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		autoreconf compiler:c++11-lang libtool pathfix pkgconfig
CONFIGURE_ARGS=	--with-pic
CPPFLAGS+=	-I${LOCALBASE}/include/json-c
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-ljson-c
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	ntop
GH_PROJECT=	nDPI
GH_TAGNAME=	cf06823

PLIST_SUB=	MAJOR_VER=${PORTVERSION:C/([[:digit:]])+\.([[:digit:]])+.*/\1.\2/}.0

post-patch:
	cd ${WRKSRC} && ${SH} autogen.sh

.include <bsd.port.mk>
