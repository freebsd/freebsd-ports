# New ports collection makefile for:	procmap
# Date created:		22 March 2000
# Whom:			Jason Evans <jasone@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	procmap
PORTVERSION=	1.0
CATEGORIES=	sysutils
DISTFILES=	#empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print the contents of a procfs map file

NO_WRKSUBDIR=	yes
MAKE_ENV=	MAKEOBJDIRPREFIX=${WRKSRC} MAKEOBJDIR=${WRKSRC}

procmap_files := Makefile procmap.c procmap.8

post-extract:
	cd ${FILESDIR} ; \
		${CP} -p ${procmap_files} ${WRKSRC}

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} obj

.include <bsd.port.mk>
