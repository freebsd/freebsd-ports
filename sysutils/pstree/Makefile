# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstree
PORTVERSION=	2.36
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.thp.uni-due.de/pub/source/ \
		LOCAL/jgh/sysutils/${PORTNAME}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	List processes as a tree

USES=		alias
NO_WRKSUBDIR=	yes

CONFLICTS=	psmisc-[0-9]*

PLIST_FILES=	bin/pstree

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/pstree ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
