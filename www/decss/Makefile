# New ports collection makefile for:   decss
# Version required:		1.0
# Date Created:			20 Feb 2000
# Whom:				Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	decss
PKGNAME=	decss-1.0
CATEGORIES=	www
MASTER_SITES=	http://www.totse.com/DeCSS/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/source

NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/DeCSS ${PREFIX}/bin/decss

.include <bsd.port.mk>
