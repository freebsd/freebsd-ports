# Ports collection makefile for:  pstree
# Date created:			  22 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstree
PORTVERSION=	2.17
CATEGORIES=    	sysutils
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	kris@FreeBSD.org

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/pstree ${PREFIX}/bin/pstree

.include <bsd.port.mk>
