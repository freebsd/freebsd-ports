# $FreeBSD$

PORTNAME=	icingaweb2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.2
CATEGORIES=	net-mgmt www

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Next generation web interface for Icinga 1 and 2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=        ${LOCALBASE}/share/ZendFramework/bin/classmap_generator.php:www/zend-framework

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes

USE_PHP_BUILD=	yes # Needed for creation of webserver configs during installation
USE_PHP=	ctype dom gd gettext hash json openssl session sockets

SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR=${WWWDIR} \
		ETCDIR=${ETCDIR} \
		EXAMPLESDIR=${EXAMPLESDIR}

PLIST_SUB=	WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

OPTIONS_DEFINE=		NLS LDAP MYSQL PGSQL
OPTIONS_DEFAULT=	LDAP MYSQL PGSQL

NLS_USES=	gettext
PGSQL_USE=	PHP=pdo_pgsql
MYSQL_USE=	PHP=pdo_mysql
LDAP_USE=	PHP=ldap

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/etc/bash_completion.d/icingacli \
		${STAGEDIR}${EXAMPLESDIR}/bash_completion.d
	(cd ${WRKSRC} && ${RM} -r .mailmap changelog.py icingaweb2.spec \
		bin/license_writer.py packages test)
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${CHMOD} 755 ${STAGEDIR}/${WWWDIR}/bin/icingacli
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for webserver in apache nginx
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${webserver}
	(cd ${STAGEDIR}${WWWDIR} && \
	./bin/icingacli setup config webserver ${webserver} --path=/icingaweb2 \
	--root=${WWWDIR}/public --config=${ETCDIR} \
	--file=${STAGEDIR}${EXAMPLESDIR}/${webserver}/icingaweb2.conf)
.endfor

.include <bsd.port.mk>
