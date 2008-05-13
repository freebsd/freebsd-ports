# New ports collection makefile for:	jailer
# Date created:	   27 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	jailer
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://memberwebs.com/stef/freebsd/jails/jailer/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Manage FreeBSD jail startup, shutdown and console

GNU_CONFIGURE=	YES

MAN8=		injail.8 jailer.8

PLIST_FILES=	bin/injail \
		sbin/dmesg \
		sbin/halt \
		sbin/jailer \
		sbin/reboot

.include <bsd.port.mk>
