# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstree
PORTVERSION=	2.35
CATEGORIES=	sysutils
MASTER_SITES=	http://www.thp.uni-due.de/pstree/ \
		LOCAL/avl
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	List processes as a tree

NO_WRKSUBDIR=	yes

CONFLICTS=	psmisc-[0-9]*

PLIST_FILES=	bin/pstree

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/pstree ${PREFIX}/bin

.include <bsd.port.mk>
