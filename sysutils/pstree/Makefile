# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstree
PORTVERSION=	2.38
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.thp.uni-due.de/pub/source/ \
		LOCAL/jgh/sysutils/${PORTNAME}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	List processes as a tree

USES=		alias
NO_WRKSUBDIR=	yes

CONFLICTS=	psmisc-[0-9]*

PLIST_FILES=	bin/pstree man/man1/pstree.1.gz

do-build:
	cd ${WRKDIR} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/pstree ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/pstree.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
