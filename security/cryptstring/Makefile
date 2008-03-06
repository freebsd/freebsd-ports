# New ports collection makefile for:	cryptstring
# Date created:		2007-02-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cryptstring
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gslin@gslin.org
COMMENT=	Crypto Strings for PHP

NO_BUILD=	yes
USE_PHP=	mcrypt mhash

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cs.inc.php ${DATADIR}

.include <bsd.port.mk>
