# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magento
PORTVERSION=	1.8.1.0
PORTREVISION=	1
CATEGORIES=	www finance
MASTER_SITES=	http://www.magentocommerce.com/downloads/assets/${PORTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Feature-rich eCommerce platform

IGNORE_WITH_PHP=	70 71 72

USES=		cpe php
CPE_VENDDOR=	magentocommerce
USE_PHP=	pdo_mysql hash gd iconv curl dom soap simplexml mcrypt mysql \
		ctype zlib json
WRKSRC=		${WRKDIR}/magento
#OPTIONS_DEFINE=	OAUTH SESSIONS REDIS SNAPPY EXAMPLES
OPTIONS_DEFINE=	OAUTH SESSIONS REDIS EXAMPLES
OAUTH_DESC=	Depend on pecl-oauth for REST API
SESSIONS_DESC=	Mark Cm/RedisSession module active
REDIS_DESC=	Depend on php56-redis for faster redis backend
#SNAPPY_DESC=	Use google snappy for Redis Cache compression

NO_BUILD=	yes
NO_ARCH=	yes
MAGENTODIR?=	www/magento

OAUTH_RUN_DEPENDS=	pecl-oauth>=1.2.3:net/pecl-oauth@${PHP_FLAVOR}
REDIS_USE=	php=redis

# First need to submit the port
#SNAPPY_RUN_DEPENDS=	php5-snappy>=0.0.2:archivers/php5-snappy

SUB_FILES=	pkg-message cron.sh pkg-install crontab
SUB_LIST=	MAGENTODIR=${MAGENTODIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PLIST_SUB=	${SUB_LIST}
PORTEXAMPLES=	*

post-patch:
	@${RM} ${WRKSRC}/cron.sh ${WRKSRC}/.htaccess

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MAGENTODIR}
	${INSTALL_SCRIPT} ${WRKDIR}/cron.sh ${STAGEDIR}${PREFIX}/${MAGENTODIR}
	@${FIND} ${STAGEDIR}${PREFIX}/${MAGENTODIR}/var -type d \
		-exec ${CHMOD} a+w {} +
	@${CHMOD} a+x ${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc \
		${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc/modules

do-install-SESSIONS-on:
	@${REINPLACE_CMD} -e 's,<active>false,<active>true,' \
		${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc/modules/Cm_RedisSession.xml
	@${RM} ${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc/modules/Cm_RedisSession.xml.bak

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/crontab ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
