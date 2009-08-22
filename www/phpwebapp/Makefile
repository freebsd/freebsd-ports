# ex:ts=8
# Ports collection makefile for:	phpwebapp
# Date created:			Jul 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	phpwebapp
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	munggo@pmy.lv
COMMENT=	A web application framework

USE_PHP=	yes
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PHPWEBAPP?=	${PREFIX}/www/data/web_app

do-install:
	${MKDIR} -p ${PREFIX}/www/data
	${CP} -R ${WRKSRC}/web_app/ ${PHPWEBAPP}
	@${FIND} ${PHPWEBAPP} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PHPWEBAPP} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/www/data 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
