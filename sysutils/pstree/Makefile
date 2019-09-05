# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstree
PORTVERSION=	2.39
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.thp.uni-due.de/pub/source/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	List processes as a tree

USES=		alias

NO_WRKSUBDIR=	yes

CONFLICTS=	psmisc-[0-9]*

PLIST_FILES=	bin/pstree man/man1/pstree.1.gz

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstree ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pstree.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
