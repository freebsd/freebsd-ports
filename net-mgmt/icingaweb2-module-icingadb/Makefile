PORTNAME=	icingaweb2-module-icingadb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Publish, synchronize, and visualize Icinga data
WWW=		https://icinga.com/docs/icinga-db-web/latest/doc/01-About/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icinga-php-library${PHP_PKGNAMESUFFIX}>=0.9:net-mgmt/icinga-php-library@${PHP_FLAVOR} \
		icinga-php-thirdparty${PHP_PKGNAMESUFFIX}>=0.11.0:net-mgmt/icinga-php-thirdparty@${PHP_FLAVOR} \
		icingadb>0:net-mgmt/icingadb \
		icingaweb2${PHP_PKGNAMESUFFIX}>=2.9:net-mgmt/icingaweb2@${PHP_FLAVOR}

USES=		php:web,flavors shebangfix
# php json extension is required but it's statically linked in default php
USE_PHP=	curl dom xml
IGNORE_WITH_PHP=	81

USE_GITHUB=	yes
GH_ACCOUNT=	icinga
GH_PROJECT=	icingadb-web

NO_BUILD=	yes
NO_ARCH=	yes

#SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR=${ETCDIR} \
		EXAMPLESDIR=${EXAMPLESDIR} \
		WWWDIR=${WWWDIR}

PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL PGSQL

PDF_DESC=		Export graphs as PDF
PDF_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:graphics/pecl-imagick@${PHP_FLAVOR}

PGSQL_USE=	PHP=pdo_pgsql,pgsql
MYSQL_USE=	PHP=mysqli,pdo_mysql

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	(cd ${WRKSRC} && ${RM} -r .mailmap changelog.py icingaweb2.spec \
		bin/license_writer.py packages test)
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
