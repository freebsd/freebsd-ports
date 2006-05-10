# New ports collection makefile for:	rc
# Date created:		Sun Aug 13 12:36:14 CDT 1995
# Whom:			erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	rc
PORTVERSION=	1.7.1
CATEGORIES=	shells plan9
MASTER_SITES=	ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/

MAINTAINER=	saken@hotel.rmta.org
COMMENT=	A unix incarnation of the plan9 shell

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-history
MAN1=		history.1 rc.1

.if defined(WITH_READLINE)
CONFIGURE_ARGS+=	--with-readline
.endif
.if !defined(WITH_READLINE)
MAKE_ARGS+=	CFLAGS="$(CFLAGS) -static"
.endif

.include <bsd.port.mk>
