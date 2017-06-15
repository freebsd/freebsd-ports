# Created by: Dirk-Willem van Gulik / dirkx@webweaving.org
# $FreeBSD$

PORTNAME=	widentd
PORTVERSION=	1.04
CATEGORIES=	net ipv6
MASTER_SITES=	http://BSDforge.com/projects/source/net/widentd/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	RFC1413 auth/identd daemon providing a fixed fake reply

LICENSE=	BSD3CLAUSE

USES=		ncurses uidfix tar:xz
MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man"
MAKE_ENV+=	NO_WERROR="defined"

PLIST_FILES=	sbin/widentd man/man8/widentd.8.gz
USE_RC_SUBR=	widentd

.include <bsd.port.mk>
