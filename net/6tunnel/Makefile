# New ports collection makefile for:	6tunnel
# Date created:		Sun Nov 19 12:51:37 CET 2000
# Whom:			Vassili Tchersky <vt@bsdjeunz.org>
#
# $FreeBSD$
#

PORTNAME=	6tunnel
PORTVERSION=	0.11.r1
CATEGORIES=	net ipv6
MASTER_SITES=	http://toxygen.net/6tunnel/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}rc1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP proxy for applications that don't speak IPv6

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
GNU_CONFIGURE=	yes
ALL_TARGET=	default

MAN1=		6tunnel.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/6tunnel

.include <bsd.port.mk>
