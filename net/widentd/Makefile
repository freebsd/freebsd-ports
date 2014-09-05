# Created by: Dirk-Willem van Gulik / dirkx@webweaving.org
# $FreeBSD$

PORTNAME=	widentd
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.webweaving.org/widentd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirkx@webweaving.org
COMMENT=	RFC1413 auth/identd daemon with fixed fake reply

USES=		uidfix
MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man"

PLIST_FILES=	sbin/widentd \
		man/man8/widentd.8.gz
USE_RC_SUBR=	widentd

BROKEN_powerpc=		Does not compile on powerpc

.include <bsd.port.mk>
