# New ports collection makefile for:	procmap
# Version required:	(self contained)
# Date created:		22 March 2000
# Whom:			Jason Evans <jasone@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	procmap-1.0
CATEGORIES=	sysutils
DISTFILES=	#empty

MAINTAINER=	jasone@freebsd.org

# setting MAKEOBJDIR doesn't work for some reason
MAKE_ENV=	MAKEOBJDIRPREFIX=${WRKDIR}
WRKSRC=		${.CURDIR}/src

pre-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} obj

.include <bsd.port.mk>
