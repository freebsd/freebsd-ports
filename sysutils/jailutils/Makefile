# New ports collection makefile for:	jailutils
# Date created:	   27 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	jailutils
PORTVERSION=	0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	http://memberwebs.com/nielsen/freebsd/jails/jailutils/

MAINTAINER=	skv@FreeBSD.org

GNU_CONFIGURE=	YES

MAN8=		jails.8 killjail.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=		"Currently does not support -CURRENT"
.endif

.include <bsd.port.post.mk>
