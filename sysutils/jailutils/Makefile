# New ports collection makefile for:	jailutils
# Date created:	   27 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	jailutils
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://memberwebs.com/nielsen/freebsd/jails/jailutils/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Several utilies for managing jails

GNU_CONFIGURE=	YES

.include <bsd.port.pre.mk>

SUP_OS_VER=     400000
.if ${OSVERSION} < ${SUP_OS_VER}
BROKEN=         "OS versions prior to ${SUP_OS_VER} is not supported"
.elif ${OSVERSION} > 501000
PLIST_FILES=	sbin/jps sbin/jid sbin/jstart sbin/jkill sbin/jails
MAN8=		jps.8 jid.8 jstart.8 jkill.8 jails.8
.else
PLIST_FILES=	sbin/jails sbin/jstart sbin/killjail
MAN8=		jails.8 jstart.8 killjail.8
.endif

.include <bsd.port.post.mk>
