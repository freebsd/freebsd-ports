# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	phpscheduleit
PORTVERSION=	1.2.12
CATEGORIES=	www
MASTER_SITES=	SF/phpscheduleit/1.%20phpScheduleIt/${PORTVERSION}
DISTNAME=	phpScheduleIt_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web-based resource scheduling and management system

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

RUN_DEPENDS+=	php:${PORTSDIR}/lang/php5 \
		${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB

PEARDIR=	${PREFIX}/share/pear
USE_PHP+=	mysql
USE_MYSQL=	yes
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=      pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

OPTIONS_DEFINE=	PGSQL APACHE LIGHTTPD
OPTIONS_DEFAULT=APACHE 

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
