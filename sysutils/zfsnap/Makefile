# New ports collection makefile for:	zfsnap
# Date created:				2010-08-02
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	zfsnap
PORTVERSION=	1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://files.bsdroot.lv/pub/FreeBSD/distfiles/
DISTNAME=	zfSnap-${PORTVERSION}

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Simple sh script to make zfs rolling snaphosts with cron

PLIST_FILES=	sbin/zfSnap

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfSnap.sh ${PREFIX}/sbin/zfSnap

# vim: set ts=8 sw=8:
.include <bsd.port.mk>
