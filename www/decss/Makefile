# New ports collection makefile for:   decss
# Date Created:			20 Feb 2000
# Whom:				Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	decss
PORTVERSION= 	1.0
CATEGORIES=	www perl5
MASTER_SITES=	http://www.totse.com/DeCSS/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/source

NO_BUILD=	YES
USE_PERL5=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/DeCSS ${PREFIX}/bin/decss

.include <bsd.port.mk>
