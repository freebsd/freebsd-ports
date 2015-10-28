# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	inotify-tools
PORTVERSION=	3.14
CATEGORIES=	sysutils
DISTVERSIONPREFIX=	v

MAINTAINER=	yuri@rawbw.com
COMMENT=	Command-line utilities to watch for file events

LICENSE=	AGPLv3

LIB_DEPENDS=	libinotify.so:${PORTSDIR}/devel/libinotify

USE_GITHUB=	yes
GH_ACCOUNT=	rvoicilas

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-linotify

.include <bsd.port.mk>
