# New ports collection makefile for:   backupninja
# Date created:        7 june 2006
# Whom:                anarcat
#
# $FreeBSD$
#

PORTNAME=	nagircbot
PORTVERSION=	0.0.20
CATEGORIES=	net-mgmt irc
MASTER_SITES=	http://www.vanheusden.com/nagircbot/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	IRC bot for Nagios

USE_GMAKE=	yes
USE_RC_SUBR=	nagircbot

PLIST_FILES=	bin/nagircbot

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=	need at least FreeBSD-6
.endif

.include <bsd.port.post.mk>
