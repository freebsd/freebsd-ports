# Created by: Timothy Redaelli <drizzt@gufi.org>
# $FreeBSD$

PORTNAME=	pkg_rmleaves
PORTVERSION=	20050922
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://utenti.gufi.org/~drizzt/codes/ports/${PORTNAME}/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Interactive script for deinstalling 'leaf' packages

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		pkg_rmleaves.1

PLIST_FILES=	sbin/pkg_rmleaves

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_rmleaves ${PREFIX}/sbin/pkg_rmleaves
	${INSTALL_MAN} ${WRKSRC}/pkg_rmleaves.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
