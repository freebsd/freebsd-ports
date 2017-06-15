# Created by: Amir Husaini <amir.husaini@bsdit.com>
# $FreeBSD$

PORTNAME=	zikula
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.bsdit.com/pub/ \
		http://zikula.at/
DISTNAME=	Zikula_Core-${PORTVERSION}.build20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MVC web application framework (PHP/MySQL)

WRKSRC=		${WRKDIR}/Zikula_Core-${PORTVERSION}
USES=		zip
NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	ctype tokenizer pdo mysql filter mbstring session json pdo_mysql hash
WANT_PHP_WEB=	yes
IGNORE_WITH_MYSQL=	41 50

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
