# Created by: Dirk-Willem van Gulik / dirkx@webweaving.org
# $FreeBSD$

PORTNAME=	widentd
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://BSDforge.com/projects/source/net/widentd/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	RFC1413 auth/identd daemon providing a fixed fake reply

LICENSE=	BSD3CLAUSE

USES=		ncurses uidfix tar:xz
USE_RC_SUBR=	widentd
MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man"

PLIST_FILES=	sbin/widentd man/man8/widentd.8.gz

.include <bsd.port.mk>

.if ${OSREL:R} < 13
MAKE_ENV+=NO_WERROR=1
.else
MAKE_ENV+=MK_WERROR=no
.endif
