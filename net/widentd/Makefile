# ex:ts=8
# New ports collection makefile for:	widentd
# Date created:			Mar 3, 2001
# Whom:				Dirk-Willem van Gulik / dirkx@webweaving.org
#
# $FreeBSD$
#

PORTNAME=	widentd
PORTVERSION=	1.03
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.webweaving.org/widentd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirkx@webweaving.org
COMMENT=	RFC1413 auth/identd daemon with fixed fake reply

MAN8=		widentd.8
MANCOMPRESSED=	yes
PLIST_FILES=	sbin/widentd

MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man"

.include <bsd.port.mk>
