# New ports collection makefile for:	pkg_rmleaves
# Date created:				26 December 2004
# Whom:					Timothy Redaelli <drizzt@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	pkg_rmleaves
PORTVERSION=	20041223
CATEGORIES=	sysutils
MASTER_SITES=	http://utenti.gufi.org/~drizzt/${PORTNAME}/

MAINTAINER=	drizzt@gufi.org
COMMENT=	Interactive script for deinstalling 'leaf' packages

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/pkg_rmleaves

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_rmleaves ${PREFIX}/sbin/pkg_rmleaves

.include <bsd.port.mk>
