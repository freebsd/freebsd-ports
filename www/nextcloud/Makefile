# $FreeBSD$

PORTNAME=	nextcloud
DISTVERSION=	18.0.1
CATEGORIES=	www
MASTER_SITES=	https://download.nextcloud.com/server/releases/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3

USES=		cpe gettext-runtime php:flavors,web tar:bzip2
USE_PHP=	bz2 ctype curl dom fileinfo filter gd hash iconv json \
		mbstring pdo posix session simplexml xml xmlreader xmlwriter \
		xsl zip zlib

NEXTCLOUD_USERNAME?=	${WWWOWN}
NEXTCLOUD_GROUPNAME?=	${WWWGRP}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	config.sample.php pkg-message
PLIST_SUB=	NEXTCLOUD_USERNAME=${NEXTCLOUD_USERNAME} \
		NEXTCLOUD_GROUPNAME=${NEXTCLOUD_GROUPNAME}

OPTIONS_DEFINE=		EXIF IMAGICK INTL LDAP PCNTL SMB SSL
OPTIONS_GROUP=		CACHING
OPTIONS_GROUP_CACHING=	APCU MEMCACHED OPCACHE REDIS
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	APCU EXIF INTL LDAP MYSQL OPCACHE SSL
OPTIONS_SUB=		yes

APCU_DESC=	Local data caching using APCu (recommended)
CACHING_DESC=	Caching
DB_DESC=	Database backend(s)
EXIF_DESC=	Image rotation support
IMAGICK_DESC=	Thumbnail support (recommended)
INTL_DESC=	International character support (recommended)
MEMCACHED_DESC=	Distributed data caching using Memcached
OPCACHE_DESC=	Enable OPcode caching (recommended)
PCNTL_DESC=	Long-running process control (recommended)
REDIS_DESC=	Distributed data caching using Redis

EXIF_USE=	PHP=exif
IMAGICK_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}imagick>=2.2.2:graphics/pecl-imagick@${PHP_FLAVOR}
INTL_USE=	PHP=intl
LDAP_USE=	PHP=ldap
MYSQL_USE=	PHP=pdo_mysql
OPCACHE_USE=	PHP=opcache
PCNTL_USE=	PHP=pcntl
PGSQL_USE=	PHP=pdo_pgsql,pgsql
REDIS_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}redis>=2.2.6:databases/pecl-redis@${PHP_FLAVOR}
SMB_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}smbclient>=0.9.0:net/pecl-smbclient@${PHP_FLAVOR}
SQLITE_USE=	PHP=pdo_sqlite,sqlite3
SSL_USE=	PHP=openssl

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPCU}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}
.endif

post-extract:
	@${MV} ${WRKSRC}/config/config.sample.php ${WRKSRC}/config/config.documented.php

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/${PORTNAME}|${WWWDIR}|;s|/var/log/|/var/log/${PORTNAME}/|' \
		${WRKSRC}/config/config.documented.php
	@${MV} ${WRKSRC}/apps ${WRKSRC}/apps-pkg

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/config.sample.php ${STAGEDIR}${WWWDIR}/config/config.sample.php
	@${RM} ${STAGEDIR}${WWWDIR}/updater/updater.phar
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	@${MKDIR} ${STAGEDIR}${WWWDIR}/apps
	@${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}

.include <bsd.port.post.mk>
