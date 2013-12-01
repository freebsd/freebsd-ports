# Created by: Timothy Redaelli <drizzt@gufi.org>
# $FreeBSD$

PORTNAME=	pkg_rmleaves
PORTVERSION=	20050922
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://utenti.gufi.org/~drizzt/codes/ports/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive script for deinstalling 'leaf' packages

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/pkg_rmleaves man/man1/pkg_rmleaves.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_rmleaves ${STAGEDIR}${PREFIX}/sbin/pkg_rmleaves
	${INSTALL_MAN} ${WRKSRC}/pkg_rmleaves.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
