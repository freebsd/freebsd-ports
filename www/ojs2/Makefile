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
COMMENT=	A journal management and publishing system

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

NO_STAGE=	yes
pre-install::
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "If you are upgrading please refer to docs/UPGRADE or browse to"
	@${ECHO_MSG} "http://pkp.sfu.ca/ojs/UPGRADE"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You need to backup your config.inc.php and your ojs2 directory"
	@${ECHO_MSG} "Hit Control-C now"
	@${ECHO_MSG} "======================================================================"

.include <bsd.port.options.mk>


.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MMEMCACHE}
USE_PHP+=	memcache
.endif

NONDOCS=	cache/fc-locale-list.php classes config.inc.php \
		dbscripts help includes index.php js lib locale pages \
		plugins public registry rt styles templates tools
.if ${PORT_OPTIONS:MDOCS}
DOCS=		docs
.endif

PLIST_SUB+=	ECHO_MSG=${ECHO_MSG}
SUB_FILES=	pkg-deinstall

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${NONDOCS}" ${WWWDIR}
	@cd ${WRKSRC} && ${CP} config.inc.php ${WWWDIR}/config.inc.php.sample
	@${INSTALL} -d ${WWWDIR}/cache/_db
	@${INSTALL} -d ${WWWDIR}/cache/t_cache
	@${INSTALL} -d ${WWWDIR}/cache/t_compile
	@${INSTALL} -d ${WWWDIR}/cache/t_config
	@${INSTALL} -d ${WWWDIR}/locale/en_US/images
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/${DOCS} && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
