# Created by Johannes Lundberg <yohanesu75@gmail.com>
# $FreeBSD$

PORTNAME=	libepoll-shim
PORTVERSION=	0.0.20160812
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	epoll shim implemented using kevent

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_PROJECT=	epoll-shim
GH_TAGNAME=	0562794

USE_LDCONFIG=	yes

USES=		uidfix
MAKE_ARGS=	LIBDIR=${PREFIX}/lib INCLUDEDIR=${PREFIX}/include

pre-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/libepoll-shim/sys

.include <bsd.port.mk>
