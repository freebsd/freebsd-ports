# New ports collection makefile for:	rc
# Date created:		Sun Aug 13 12:36:14 CDT 1995
# Whom:			erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	rc
PORTVERSION=	1.7.1
CATEGORIES=	shells plan9
MASTER_SITES=	ftp://rc.quanstro.net/pub/ \
		ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/

MAINTAINER=	quanstro@quanstro.net
COMMENT=	A unix incarnation of the plan9 shell

USE_BZIP2=	YES
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-history
MAN1=		history.1 rc.1


OPTIONS=	READLINE "Build readline support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_READLINE)
CONFIGURE_ARGS+=	--with-readline
.else
MAKE_ARGS+=	CFLAGS="$(CFLAGS) -static"
.endif

.include <bsd.port.post.mk>
