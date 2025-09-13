PORTNAME=	nextcloud
PORTVERSION=	31.0.9
CATEGORIES=	www
MASTER_SITES=	https://download.nextcloud.com/server/releases/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Collaboration platform which runs on your own server
WWW=		https://nextcloud.com

LICENSE=	AGPLv3

USES=		cpe gettext-runtime php:flavors,web tar:bzip2
USE_PHP=	bcmath bz2 ctype curl dom fileinfo filter gd gmp iconv \
		mbstring pcntl pdo posix session simplexml sodium \
		xml xmlreader xmlwriter xsl zip zlib

NEXTCLOUD_USERNAME?=	${WWWOWN}
NEXTCLOUD_GROUPNAME?=	${WWWGRP}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	config.sample.php occ pkg-message plist.post
SUB_LIST=	NEXTCLOUD_USERNAME=${NEXTCLOUD_USERNAME} \
		NEXTCLOUD_GROUPNAME=${NEXTCLOUD_GROUPNAME}
PLIST_SUB=	${SUB_LIST}

OPTIONS_DEFINE=		EXIF IMAGICK INTL LDAP PCNTL SMB SYSVSEM
OPTIONS_GROUP=		CACHING
OPTIONS_GROUP_CACHING=	APCU OPCACHE REDIS
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	APCU EXIF INTL LDAP MYSQL OPCACHE SYSVSEM
OPTIONS_SUB=		yes

APCU_DESC=	Local data caching using APCu (recommended)
CACHING_DESC=	Caching
DB_DESC=	Database backend(s)
EXIF_DESC=	Image rotation support
IMAGICK_DESC=	Thumbnail support (recommended)
INTL_DESC=	International character support (recommended)
OPCACHE_DESC=	Enable OPcode caching (recommended)
PCNTL_DESC=	Long-running process control (recommended)
REDIS_DESC=	Distributed data caching using Redis
SYSVSEM_DESC=	Enable System V semaphore support (recommended)

APCU_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}APCu>0:devel/pecl-APCu@${PHP_FLAVOR}
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
SYSVSEM_USE=	PHP=sysvsem

.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKSRC}/config/config.sample.php ${WRKSRC}/config/config.documented.php
	@${MV} ${WRKSRC}/.htaccess ${WRKSRC}/.htaccess.dist

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/${PORTNAME}|${WWWDIR}|;s|/var/log/|/var/log/${PORTNAME}/|' \
		${WRKSRC}/config/config.documented.php
	@${RM} ${WRKSRC}/config/config.documented.php.* \
		 ${WRKSRC}/updater/updater.phar
	@${RMDIR} ${WRKSRC}/apps/suspicious_login/vendor/amphp/*/docs/.shared
	@${MV} ${WRKSRC}/apps ${WRKSRC}/apps-pkg

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/config.sample.php \
		${STAGEDIR}${WWWDIR}/config/config.sample.php
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data ${STAGEDIR}${WWWDIR}/apps \
		${STAGEDIR}/var/log/${PORTNAME}
	(cd ${WRKSRC}; ${FIND} . -type f -or -type l) | ${SORT} | \
		${SED} -Ee '/^\.\/\.(htaccess\.dist|user\.ini)/d' \
			-e '/^\.\/config\/config\.sample\.php/d' \
			-e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}
	${CAT} ${WRKDIR}/plist.post >> ${TMPPLIST}
	${INSTALL_SCRIPT} ${WRKDIR}/occ ${STAGEDIR}${LOCALBASE}/bin/occ

.include <bsd.port.mk>
