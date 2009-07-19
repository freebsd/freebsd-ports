# New ports collection makefile for:	6tunnel
# Date created:		Sun Nov 19 12:51:37 CET 2000
# Whom:			Vassili Tchersky <vt@bsdjeunz.org>
#
# $FreeBSD$
#

PORTNAME=	6tunnel
DISTVERSION=	0.11rc2
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://toxygen.net/6tunnel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP proxy for applications that don't speak IPv6

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}rc2

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262
ALL_TARGET=	default

MAN1=		6tunnel.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/6tunnel

.include <bsd.port.mk>
