# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	inotify-tools
PORTVERSION=	3.14.01
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	yuri@rawbw.com
COMMENT=	Command-line utilities to watch for file events

LICENSE=	AGPLv3

LIB_DEPENDS=	libinotify.so:devel/libinotify

USE_GITHUB=	yes
GH_ACCOUNT=	rvoicilas
GH_TAGNAME=	1df9af4

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
