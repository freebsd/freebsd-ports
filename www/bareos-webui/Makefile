# $FreeBSD$

PORTNAME=       bareos
DISTVERSIONPREFIX=      Release/
DISTVERSION=    18.2.7
CATEGORIES?=    www sysutils
PKGNAMESUFFIX= -webui

MAINTAINER=	acm@FreeBSD.org
COMMENT=	PHP-Frontend to manage Bareos over the web

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/webui/LICENSE

USE_GITHUB=	yes

USES=		php
USE_PHP=	openssl gettext ctype hash json session iconv
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	BAREOSWEBUIDIR=${WWWDIR}

OPTIONS_DEFINE=		MYSQL PGSQL ZENDFRAMEWORK
OPTIONS_DEFAULT=	PGSQL
ZENDFRAMEWORK_DESC=	Install zend framework

MYSQL_USE=		PHP=pdo_mysql
PGSQL_USE=		PHP=pdo_pgsql
ZENDFRAMEWORK_RUN_DEPENDS=	${LOCALBASE}/share/ZendFramework/bin/classmap_generator.php:www/zend-framework

post-extract:
	${RM} ${WRKSRC}/webui/config/autoload/.gitignore
	${RM} ${WRKSRC}/webui/data/cache/.gitignore
	${RM} ${WRKSRC}/webui/vendor/.gitignore
	${MV} ${WRKSRC}/webui/version.php.in ${WRKSRC}/webui/version.php
	${MV} ${WRKSRC}/webui/config/autoload/global.php.in ${WRKSRC}/webui/config/autoload/global.php
	${MV} ${WRKSRC}/webui/module/Application/view/layout/layout.phtml.in ${WRKSRC}/webui/module/Application/view/layout/layout.phtml
	${MV} ${WRKSRC}/webui/module/Application/view/layout/login.phtml.in ${WRKSRC}/webui/module/Application/view/layout/login.phtml

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${LOCALBASE}/etc/|g' -e 's|@WEBUICONFDIR@|${ETCDIR}|g' -e \
		's|@dirport@|9101|g' ${WRKSRC}/webui/config/autoload/global.php
	@${REINPLACE_CMD} -e 's|@BAREOS_FULL_VERSION@|${PORTVERSION}|g' ${WRKSRC}/webui/version.php

do-install:
	@${ECHO} "Installing in ${WWWDIR}"
	@${MKDIR} ${STAGEDIR}${ETCDIR}/bareos-dir.d/console
	@${MKDIR} ${STAGEDIR}${ETCDIR}/bareos-dir.d/profile
	@${MKDIR} ${STAGEDIR}${BAREOSWEB_HOME}
	cd ${WRKSRC}/webui && ${COPYTREE_SHARE} "config data module public vendor" \
		${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/*.php ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/composer* ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/phpunit.xml ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webui/install/directors.ini.in ${STAGEDIR}${ETCDIR}/directors.ini
	${INSTALL_DATA} ${WRKSRC}/webui/install/configuration.ini.in ${STAGEDIR}${ETCDIR}/configuration.ini
	${INSTALL_DATA} ${WRKSRC}/webui/install/bareos/bareos-dir.d/console/admin.conf.example ${STAGEDIR}${ETCDIR}/bareos-dir.d/console/admin.conf.sample
	${INSTALL_DATA} ${WRKSRC}/webui/install/bareos/bareos-dir.d/profile/webui-admin.conf ${STAGEDIR}${ETCDIR}/bareos-dir.d/profile/webui-admin.conf.sample
	${INSTALL_DATA} ${WRKSRC}/webui/install/apache/bareos-webui.conf ${STAGEDIR}${ETCDIR}/apache-bareos-webui.conf
	${INSTALL_DATA} ${WRKSRC}/webui/install/nginx/bareos-webui.conf ${STAGEDIR}${ETCDIR}/nginx-bareos-webui.conf

.include <bsd.port.mk>
