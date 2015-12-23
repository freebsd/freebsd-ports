# Created by: Filipe Rocha <filiperocha@gmail.com>
# $FreeBSD$

PORTNAME=	ojs2
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pkp.sfu.ca/ojs/download/ \
		http://socpvs.org/pkp/ \
		LOCAL/glarkin
DISTNAME=	ojs-2.2.1

MAINTAINER=	filiperocha@gmail.com
COMMENT=	Journal management and publishing system

DEPRECATED=	PHP 5.4 EOL reached
EXPIRATION_DATE=	2016-01-15

DIST_SUBDIR=	${PORTNAME}

NO_BUILD=	yes
USE_PHP=	mbstring session
DEFAULT_PHP_VER=5
WANT_PHP_WEB=	yes

OPTIONS_DEFINE=	LDAP CURL MEMCACHE DOCS
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL LDAP
MEMCACHE_DESC=	memcached cache system
DB_DESC=	DB backend

pre-install::
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "If you are upgrading please refer to docs/UPGRADE or browse to"
	@${ECHO_MSG} "http://pkp.sfu.ca/ojs/UPGRADE"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You need to backup your config.inc.php and your ojs2 directory"
	@${ECHO_MSG} "Hit Control-C now"
	@${ECHO_MSG} "======================================================================"

MYSQL_USE=	php=mysql
PGSQL_USE=	php=pgsql
LDAP_USE=	php=ldap
CURL_USE=	php=curl
MEMCACHE_USE=	php=memcache

NONDOCS=	cache/fc-locale-list.php classes config.inc.php \
		dbscripts help includes index.php js lib locale pages \
		plugins public registry rt styles templates tools
DOCS=		docs

PLIST_SUB+=	ECHO_MSG=${ECHO_MSG}
SUB_FILES=	pkg-deinstall

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${NONDOCS}" ${STAGEDIR}${WWWDIR}
	${MV} ${STAGEDIR}${WWWDIR}/config.inc.php ${STAGEDIR}${WWWDIR}/config.inc.php.sample
	${INSTALL} -d ${STAGEDIR}${WWWDIR}/cache/_db
	${INSTALL} -d ${STAGEDIR}${WWWDIR}/cache/t_cache
	${INSTALL} -d ${STAGEDIR}${WWWDIR}/cache/t_compile
	${INSTALL} -d ${STAGEDIR}${WWWDIR}/cache/t_config
	${INSTALL} -d ${STAGEDIR}${WWWDIR}/locale/en_US/images

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/${DOCS} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
