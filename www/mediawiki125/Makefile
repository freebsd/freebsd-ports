# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	mediawiki
PORTVERSION=	1.25.6
CATEGORIES=	www
MASTER_SITES=	http://releases.wikimedia.org/mediawiki/${PORTVERSION:R}/
PKGNAMESUFFIX=	125

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Wiki engine used by Wikipedia

LICENSE=	GPLv2

CONFLICTS=	mediawiki12[346]-[0-9]*

USES=		shebangfix
SHEBANG_FILES=	maintenance/dev/*.sh \
		maintenance/hiphop/run-server \
		vendor/leafo/lessphp/lessify \
		maintenance/postgres/*.pl \
		maintenance/storage/make-blobs \
		includes/limit.sh
SHEBANG_LANG=	hhvm
hhvm_OLD_CMD=	/usr/bin/hhvm
hhvm_CMD=	${LOCALBASE}/bin/hhvm # not installed by anything yet
USE_PHP=	ctype dom hash iconv json mbstring pcre readline \
		session xml xmlreader zlib
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/mediawiki

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist

SUB_FILES=	pkg-message
SUB_LIST=	MEDIAWIKIDIR=${PREFIX}/${MEDIAWIKIDIR}

OPTIONS_DEFINE=		LDAP MEMCACHED IMAGICK SOCKETS
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_RADIO=		ACCEL
OPTIONS_RADIO_ACCEL=	APC XCACHE
OPTIONS_DEFAULT=	MYSQL SOCKETS

MEMCACHED_DESC=	Use memcached
APC_DESC=	Use pecl-APC (Mediawiki recommended)
XCACHE_DESC=	Use xCache (instead of pecl-APC)
IMAGICK_DESC=	Use ImageMagick
SOCKETS_DESC=	Use sockets

MYSQL_USE=	mysql=client php=mysql
MYSQL_VARS=	IGNORE_WITH_PHP+=70
PGSQL_USE=	php=pgsql
SQLITE_USE=	php=sqlite3
LDAP_USE=	php=ldap
SOCKETS_USE=	php=sockets

MEMCACHED_RUN_DEPENDS=	memcached:databases/memcached
IMAGICK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:graphics/pecl-imagick
APC_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apc.so:www/pecl-APC
XCACHE_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xcache.so:www/xcache

pre-install:
	@${FIND} -s -d ${WRKSRC} -not -type d | ${SED} "s?${WRKSRC}?${MEDIAWIKIDIR}?g" >>${PLIST}
	@${ECHO} "@dir %%WWWDIR%%/vendor/monolog/monolog/tests/Monolog/Handler/Fixtures" >> ${PLIST}
	@${ECHO} "@mode 0777" >> ${PLIST}
	@${ECHO} "@dir %%WWWDIR%%/images" >> ${PLIST}
	@${ECHO} "@mode" >> ${PLIST}
	@${ECHO} @dir ${MEDIAWIKIDIR} >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MEDIAWIKIDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MEDIAWIKIDIR}

.include <bsd.port.mk>
