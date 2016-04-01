# Created by: William Ward <William.Ward@ericsson.com>
# $FreeBSD$

PORTNAME=	nylon
PORTVERSION=	1.21
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/nylon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix SOCKS 4 and 5 proxy server

LIB_DEPENDS=	libevent.so:devel/libevent2

USE_RC_SUBR=	nylon

USES=		pkgconfig
GNU_CONFIGURE=	yes
# Necessary for $PREFIX to work:
CONFIGURE_ARGS=	--with-libevent=yes
CONFIGURE_ENV=	EVENTLIB="`pkgconf --libs libevent`" EVENTINC="`pkgconf --cflags libevent`"


PLIST_FILES=	bin/nylon etc/nylon.conf.sample man/man1/nylon.1.gz

post-install:
	${INSTALL_DATA} ${FILESDIR}/nylon.conf ${STAGEDIR}${PREFIX}/etc/nylon.conf.sample

.include <bsd.port.mk>
