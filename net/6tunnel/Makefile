# New ports collection makefile for:	6tunnel
# Date created:		Sun Nov 19 12:51:37 CET 2000
# Whom:			Vassili Tchersky <vt@bsdjeunz.org>
#
# $FreeBSD$
#

PORTNAME=	6tunnel
PORTVERSION=	0.09
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://amba.bydg.pdi.net/pub/wojtekka/ \
		ftp://ftp.bsdfr.org/pub/projects/6tunnel/ \
		ftp://atlantis.bsd-fr.org/pub/ipv6/tools/ \
		http://rencade.raphit.net/~vt/

MAINTAINER=	vt@bsd-fr.org
COMMENT=	TCP proxy for application that don't speak IPv6

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	default

MAN1=		6tunnel.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/6tunnel

.include <bsd.port.mk>
