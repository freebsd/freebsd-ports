# New ports collection makefile for:	portmaster
# Date created:				20 February 2006
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the files directory.
#

PORTNAME=	portmaster
PORTVERSION=	2.8
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Manage your ports without external databases or languages

NO_BUILD=	yes
SUB_FILES=	portmaster.sh

PLIST_FILES=	sbin/portmaster

MAN8=		portmaster.8

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/portmaster.sh ${PREFIX}/sbin/portmaster
	${INSTALL_MAN} ${FILESDIR}/portmaster.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
