# Ports collection makefile for:  pstree
# Date created:			  22 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstree
PORTVERSION=	2.21
CATEGORIES=	sysutils
MASTER_SITES=	http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	List processes as a tree

NO_WRKSUBDIR=	yes

CONFLICTS=	psmisc-*

PLIST_FILES=	bin/pstree

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/pstree ${PREFIX}/bin/pstree

.include <bsd.port.mk>
