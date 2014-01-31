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

PLIST_FILES=	sbin/widentd \
		man/man8/widentd.8.gz
USE_RC_SUBR=	widentd

MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man"

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
