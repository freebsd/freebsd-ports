PORTNAME=       bareos
DISTVERSIONPREFIX=      Release/
DISTVERSION=    19.2.9
PORTREVISION=	3
CATEGORIES?=    www sysutils
PKGNAMESUFFIX=	19-webui

MAINTAINER=	acm@FreeBSD.org
COMMENT=	PHP-Frontend to manage Bareos over the web

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/webui/LICENSE

USE_GITHUB=	yes

USES=		cmake gettext php:build
USE_PHP=	ctype gettext hash iconv json openssl session
NO_BUILD=	yes
NO_ARCH=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/webui
CMAKE_INSTALL_PREFIX=	${STAGEDIR}
CMAKE_ARGS+=		-DSHARE_INSTALL_PREFIX:PATH=${PREFIX}/www \
			-DCMAKE_INSTALL_FULL_SYSCONFDIR:PATH=${PREFIX}/etc \
			-Dsysconfdir=${PREFIX}/etc \
			-Dwebuiconfdir=${PREFIX}/${ETCDIRWEBUI}

SUB_FILES=		pkg-message
SUB_LIST+=		ETCDIRWEBUI=${PREFIX}/${ETCDIRWEBUI}
PLIST_SUB+=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} ETCDIRWEBUI=${ETCDIRWEBUI}
ETCDIRWEBUI=		etc/${PORTNAME}${PKGNAMESUFFIX:S/19//}

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	PGSQL

MYSQL_USE=		PHP=pdo_mysql
PGSQL_USE=		PHP=pdo_pgsql

post-extract:
	${FIND} ${WRKSRC}/webui -name .gitignore -delete

pre-install:
	${FIND} ${WRKSRC}/webui -name *.in -delete

do-install:
	@${ECHO} "Installing in ${WWWDIR}"
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ETCDIRWEBUI}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/bareos-dir.d/console
	@${MKDIR} ${STAGEDIR}${ETCDIR}/bareos-dir.d/profile
	@${MKDIR} ${STAGEDIR}${BAREOSWEB_HOME}
	cd ${WRKSRC}/webui && ${COPYTREE_SHARE} "config data module public vendor" \
		${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/*.php ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/composer* ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/phpunit.xml ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/install/directors.ini ${STAGEDIR}/${PREFIX}/${ETCDIRWEBUI}/directors.ini
	${INSTALL_DATA} ${WRKSRC}/webui/install/configuration.ini ${STAGEDIR}/${PREFIX}/${ETCDIRWEBUI}/configuration.ini
	${INSTALL_DATA} ${WRKSRC}/webui/install/bareos/bareos-dir.d/console/admin.conf.example ${STAGEDIR}${ETCDIR}/bareos-dir.d/console/admin.conf.sample
	${INSTALL_DATA} ${WRKSRC}/webui/install/bareos/bareos-dir.d/profile/webui-admin.conf ${STAGEDIR}${ETCDIR}/bareos-dir.d/profile/webui-admin.conf.sample
	${INSTALL_DATA} ${WRKSRC}/webui/install/bareos/bareos-dir.d/profile/webui-limited.conf.example ${STAGEDIR}${ETCDIR}/bareos-dir.d/profile/webui-limited.conf.sample
	${INSTALL_DATA} ${WRKSRC}/webui/install/bareos/bareos-dir.d/profile/webui-readonly.conf ${STAGEDIR}${ETCDIR}/bareos-dir.d/profile/webui-readonly.conf.sample
	${INSTALL_DATA} ${WRKSRC}/webui/install/apache/bareos-webui.conf ${STAGEDIR}/${PREFIX}/${ETCDIRWEBUI}/apache-bareos-webui.conf
	${INSTALL_DATA} ${WRKSRC}/webui/install/nginx/bareos-webui.conf ${STAGEDIR}/${PREFIX}/${ETCDIRWEBUI}/nginx-bareos-webui.conf

.include <bsd.port.mk>
