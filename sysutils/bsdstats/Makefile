# New ports collection makefile for:	bsdstats
# Date created:		5 August 2006
# Whom:			Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	bsdstats
PORTVERSION=	1.0
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	scrappy@freebsd.org
COMMENT=	Monthly script for reporting anonymous statistics about your machine

NO_BUILD=	yes
PLIST_FILES=	etc/periodic/monthly/300.statistics

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${LOCALBASE}/etc/periodic/monthly
	${CP} ${FILESDIR}/300.statistics ${LOCALBASE}/etc/periodic/monthly
post-install:
	${CAT} pkg-message

.include <bsd.port.post.mk>
