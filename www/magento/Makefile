# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magento
PORTVERSION=	1.8.1.0
CATEGORIES=	www finance
MASTER_SITES=	http://www.magentocommerce.com/downloads/assets/${PORTVERSION}/

MAINTAINER=	melvyn@magemana.nl
COMMENT=	Feature-rich eCommerce platform

USES=		cpe
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
MAGENTODIR?=	www/magento

.include <bsd.port.options.mk>
.if !empty(${PORT_OPTIONS:MOAUTH})
RUN_DEPENDS+=	pecl-oauth>=1.2.3:net/pecl-oauth
.endif
.if !empty(${PORT_OPTIONS:MREDIS})
RUN_DEPENDS+=	php56-redis>=2.2.0:databases/php56-redis
.endif
# First need to submit the port
#.if ${PORT_OPTIONS:MSNAPPY}
#RUN_DEPENDS+=	php5-snappy>=0.0.2:archivers/php5-snappy
#.endif

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message cron.sh pkg-install crontab
SUB_LIST+=	MAGENTODIR=${MAGENTODIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PLIST_SUB+=	${SUB_LIST}


post-patch:
	@${RM} -f ${WRKSRC}/cron.sh ${WRKSRC}/.htaccess

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MAGENTODIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/cron.sh ${STAGEDIR}${PREFIX}/${MAGENTODIR}
	@${FIND} ${STAGEDIR}${PREFIX}/${MAGENTODIR}/var -type d \
		-exec ${CHMOD} a+w {} +
	@${CHMOD} a+x ${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc \
		${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc/modules
.if !empty(${PORT_OPTIONS:MSESSIONS})
	@${REINPLACE_CMD} -e 's,<active>false,<active>true,' \
		${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc/modules/Cm_RedisSession.xml
	@${RM} -f ${STAGEDIR}${PREFIX}/${MAGENTODIR}/app/etc/modules/Cm_RedisSession.xml.bak
.endif
.if !empty(${PORT_OPIONS:MEXAMPLES})
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKDIR}/crontab ${STAGEDIR}${PREFIX}/${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
