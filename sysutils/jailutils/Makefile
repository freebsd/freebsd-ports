# New ports collection makefile for:	jailutils
# Date created:	   27 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	jailutils
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://memberwebs.com/stef/freebsd/jails/jailutils/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Several utilities for managing jails

GNU_CONFIGURE=	YES

.include <bsd.port.pre.mk>

PLIST_FILES=	sbin/injail sbin/jails sbin/jid sbin/jkill sbin/jps sbin/jstart\
		sbin/killjail
MAN8=		injail.8 jails.8 jid.8 jkill.8 jps.8 jstart.8

.include <bsd.port.post.mk>
