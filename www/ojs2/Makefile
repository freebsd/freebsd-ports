# New ports collection makefile for:	ojs
# Date created:				4 March 2006
# Whom:					Filipe Rocha <filiperocha@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ojs2
PORTVERSION=	2.2.1
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

OPTIONS=	MYSQL "Use a MySQL database" on \
		PGSQL "Use a PostgreSQL database" off \
		LDAP  "Use LDAP authentication" off \
		CURL  "Use cURL" on \
		MEMCACHE "Use memcached cache system" off\

pre-install::
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "If you are upgrading please refer to docs/UPGRADE or browse to"
	@${ECHO_MSG} "http://pkp.sfu.ca/ojs/UPGRADE"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You need to backup your config.inc.php and your ojs2 directory"
	@${ECHO_MSG} "Hit Control-C now"
	@${ECHO_MSG} "======================================================================"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL)
IGNORE=		needs at least least one DB backend; please rerun 'make config'
.endif

.ifndef(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.ifdef(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.ifdef(WITH_LDAP)
USE_PHP+=	ldap
.endif

.ifdef(WITH_CURL)
USE_PHP+=	curl
.endif

.ifdef(WITH_MEMCACHE)
USE_PHP+=	memcache
.endif

NONDOCS=	cache/fc-locale-list.php classes config.inc.php \
		dbscripts help includes index.php js lib locale pages \
		plugins public registry rt styles templates tools
.if !defined(NOPORTDOCS)
DOCS=		docs
.endif

PLIST_SUB+=	ECHO_MSG=${ECHO_MSG}

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
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/${DOCS} && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@${RM} -rf ${WWWDIR}/cache

.include <bsd.port.post.mk>
