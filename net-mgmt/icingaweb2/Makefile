# $FreeBSD$

PORTNAME=	icingaweb2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.3
CATEGORIES=	net-mgmt www

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Next generation web interface for Icinga 1 and 2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	zf:www/zend-framework1

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

USES=		php:build
USE_PHP=	ctype dom gd gettext hash json openssl session sockets

SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR=${WWWDIR} \
		ETCDIR=${ETCDIR} \
		EXAMPLESDIR=${EXAMPLESDIR}

PLIST_SUB=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

OPTIONS_DEFINE=		NLS LDAP MYSQL PGSQL PDF EXAMPLES
OPTIONS_DEFAULT=	LDAP MYSQL PGSQL

PDF_DESC=	Export graphs as PDF

NLS_USES=	gettext
NLS_USE=	php=intl
PGSQL_USE=	PHP=pdo_pgsql,pgsql
MYSQL_USE=	PHP=pdo_mysql
LDAP_USE=	PHP=ldap
PDF_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:graphics/pecl-imagick@${PHP_FLAVOR}

post-patch:
	${REINPLACE_CMD} 's%\(/etc/icingaweb2\)%${PREFIX}\1%g' \
		${WRKSRC}/library/Icinga/Application/ApplicationBootstrap.php
	${REINPLACE_CMD} 's%readlink[^)]*)%"${PREFIX}/bin/php"%g' \
		${WRKSRC}/application/clicommands/WebCommand.php
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
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
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
.for webserver in apache nginx
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${webserver}
	# ICINGAWEB_CONFIGDIR is set to /nonexistent to allow staging as user.
	# Once installed, ${ETCDIR} is not world-readable, so point icingacli to
	# a non existing directory. The config files are generated correctly anyway.
	(cd ${STAGEDIR}${WWWDIR} && \
	ICINGAWEB_CONFIGDIR=/nonexistent \
	./bin/icingacli setup config webserver ${webserver} --path=/icingaweb2 \
	--root=${WWWDIR}/public --config=${ETCDIR} \
	--file=${STAGEDIR}${EXAMPLESDIR}/${webserver}/icingaweb2.conf)
.endfor

.include <bsd.port.mk>
