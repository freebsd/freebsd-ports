# Created by: ijliao
# $FreeBSD$

PORTNAME=	phpwebapp
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web application framework

USE_PHP=	yes
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PHPWEBAPP?=	${PREFIX}/www/data/web_app

do-install:
	${MKDIR} -p ${STAGEDIR}${PREFIX}/www/data
	${CP} -R ${WRKSRC}/web_app/ ${STAGEDIR}${PHPWEBAPP}
	@${FIND} ${STAGEDIR}${PHPWEBAPP} ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${PHPWEBAPP} -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/www/data 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
