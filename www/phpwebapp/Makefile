# ex:ts=8
# Ports collection makefile for:	phpwebapp
# Date created:			Jul 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	phpwebapp
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web application framework

USE_PHP=	yes
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PHPWEBAPP?=	${PREFIX}/www/data/web_app

do-install:
	${CP} -R ${WRKSRC}/web_app/ ${PHPWEBAPP}
	@${FIND} ${PHPWEBAPP} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PHPWEBAPP} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
