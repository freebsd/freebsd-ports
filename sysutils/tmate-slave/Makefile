# $FreeBSD$

PORTNAME=	tmate-slave
PORTVERSION=	g2018112801
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Instant terminal sharing server

BROKEN=		unfetchable

LIB_DEPENDS=	libevent.so:devel/libevent \
		libmsgpackc.so:devel/msgpack \
		libssh.so:security/libssh

USES=		autoreconf ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tmate-io
GH_TAGNAME=	8b294f3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/tmate-slave

PORTSCOUT=	skipv:1.8,1.7,to_copy,base

.include <bsd.port.mk>
