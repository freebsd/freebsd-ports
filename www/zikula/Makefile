# Created by: Amir Husaini <amir.husaini@bsdit.com>
# $FreeBSD$

PORTNAME=	zikula
PORTVERSION=	1.3.5
CATEGORIES=	www
MASTER_SITES=	http://www.bsdit.com/pub/ \
		http://zikula.at/
DISTNAME=	Zikula_Core-${PORTVERSION}.build20

MAINTAINER=	amir.husaini@bsdit.com
COMMENT=	MVC web application framework (PHP/MySQL)

WRKSRC=		${WRKDIR}/Zikula_Core-${PORTVERSION}
USES=		zip
NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	ctype tokenizer pdo mysql filter mbstring session json pdo_mysql hash
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=52
IGNORE_WITH_MYSQL=	41 50

SUB_FILES=	pkg-message

NO_STAGE=	yes
do-install:
	@${MKDIR} ${WWWDIR}
		@cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${WWWDIR}/{} \; \
		-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} . \! -type d -exec ${INSTALL_DATA} {} ${WWWDIR}/{} \; \
		-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
