# New ports collection makefile for:	ezload
# Date created:		18 august 2003
# Whom:			dirkx@webweaving.org
#
# $FreeBSD$
#

PORTNAME=	watchdog
PORTVERSION=	1.00
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webweaving.org/watchdog/
EXTRACT_SUFX=   .tgz

MAINTAINER=	dirkx@webweaving.org
COMMENT=	"Watchdog daemon for the AMD Elan sc520 system-on-chip."

MAN8=		watchdogd.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/watchdogd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500043
# We need revision 1.12 of /sys/i386/i386/elan-mmrc.c and
# 1.1 of /sys/sys/watchdog.h.  The first tag is RELENG_5_1.
#
IGNORE=		'This port only works on 5.1 and above /  ${OSVERSION}
.endif

.include <bsd.port.post.mk>
