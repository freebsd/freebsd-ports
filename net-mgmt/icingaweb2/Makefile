PORTNAME=	icingaweb2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.5
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Next generation web interface for Icinga 1 and 2
WWW=		https://www.icinga.com/products/icinga-web-2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icinga-php-library${PHP_PKGNAMESUFFIX}>=0.14.2:net-mgmt/icinga-php-library@${PHP_FLAVOR} \
		icinga-php-thirdparty${PHP_PKGNAMESUFFIX}>=0.12.1:net-mgmt/icinga-php-thirdparty@${PHP_FLAVOR} \
		icingaweb2-module-incubator${PHP_PKGNAMESUFFIX}>=0.20.0:net-mgmt/icingaweb2-module-incubator@${PHP_FLAVOR}

USES=		php:build,web,flavors shebangfix gettext
USE_PHP=	bcmath bitset ctype curl dom fileinfo filter gd gettext iconv intl ldap \
		mbstring mcrypt memcache memcached opcache pdo \
		pdo_sqlite posix session simplexml soap sockets sqlite3 xml \
		zlib
IGNORE_WITH_PHP=81

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

CONFLICTS_INSTALL=	icingaweb2-php* # bin/icingacli

SHEBANG_FILES=	bin/icingacli

SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR=${ETCDIR} \
		EXAMPLESDIR=${EXAMPLESDIR} \
		WWWDIR=${WWWDIR}

PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

OPTIONS_DEFINE=		EXAMPLES LDAP MYSQL PDF PGSQL SQLITE
OPTIONS_DEFAULT=	LDAP MYSQL PGSQL SQLITE

PDF_DESC=		Export graphs as PDF
PDF_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:graphics/pecl-imagick@${PHP_FLAVOR}

PGSQL_USE=	PHP=pdo_pgsql,pgsql
MYSQL_USE=	PHP=mysqli,pdo_mysql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3
LDAP_USE=	PHP=ldap

post-patch:
	${REINPLACE_CMD} 's%\(/etc/icingaweb2\)%${PREFIX}\1%g' \
		${WRKSRC}/library/Icinga/Application/ApplicationBootstrap.php
	${REINPLACE_CMD} 's%/var/lib/icingaweb2%/var/db/icingaweb2%g' \
		${WRKSRC}/library/Icinga/Application/ApplicationBootstrap.php
	${REINPLACE_CMD} 's%/usr/share/icinga-php%${WWWDIR}/icinga-php%g' \
		${WRKSRC}/library/Icinga/Application/ApplicationBootstrap.php
	${REINPLACE_CMD} 's%readlink[^)]*)%"${PREFIX}/bin/php"%g' \
		${WRKSRC}/application/clicommands/WebCommand.php
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/etc/bash_completion.d/icingacli \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	(cd ${WRKSRC} && ${RM} -r .mailmap changelog.py icingaweb2.spec \
		bin/license_writer.py packages test)
	(${FIND} ${WRKSRC} -name "*.bak" -delete)
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${CHMOD} 755 ${STAGEDIR}${WWWDIR}/bin/icingacli
	${RLN} ${STAGEDIR}${WWWDIR}/bin/icingacli ${STAGEDIR}${PREFIX}/bin/icingacli
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
