PORTNAME=	nibbleblog
DISTVERSION=	3.0.2
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}/
DISTNAME=	nibbleblogv302

MAINTAINER=	marekholienka@gmail.com
COMMENT=	Lightweight blog system for general use
WWW=		https://www.nibbleblog.com/

LICENSE=	GPLv3
LICENSE_FILE= ${WRKDIR}/${PORTNAME}/COPYRIGHT.txt

DEPRECATED=	Upstream WWW redirects to a different CMS software
EXPIRATION_DATE=	2024-02-29

RUN_DEPENDS=	pear:devel/pear@${PHP_FLAVOR}

USES=		cpe php zip
USE_PHP=	session filter xml simplexml gd
IGNORE_WITH_PHP=	82 83

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PKGMESSAGE=	${MASTERDIR}/pkg-message
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

APACHE_USES=		apache:run
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -r ${WRKDIR}/${PORTNAME}/ ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
