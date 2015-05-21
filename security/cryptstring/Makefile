# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	cryptstring
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Crypto Strings for PHP

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
USE_PHP=	mcrypt mhash

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cs.inc.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
