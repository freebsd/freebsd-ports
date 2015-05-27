# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	mediawiki
PORTVERSION=	1.25.1
CATEGORIES=	www
MASTER_SITES=	http://releases.wikimedia.org/mediawiki/${PORTVERSION:R}/
PKGNAMESUFFIX=	125

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Wiki engine used by Wikipedia

LICENSE=	GPLv2

CONFLICTS=	mediawiki119-[0-9]* mediawiki12[34]-[0-9]*

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
USE_PHP=	ctype hash iconv mbstring pcre session xml zlib readline dom json
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/mediawiki

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist

SUB_FILES=	pkg-message
SUB_LIST=	MEDIAWIKIDIR=${PREFIX}/${MEDIAWIKIDIR}

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE LDAP MEMCACHED APC EACCEL XCACHE IMAGICK
OPTIONS_DEFAULT=MYSQL

MEMCACHED_DESC=	Use memcached
APC_DESC=	Use pecl-APC (Mediawiki recommended)
EACCEL_DESC=	Use eAccelerator (instead of pecl-APC)
XCACHE_DESC=	Use xCache (instead of pecl-APC)
IMAGICK_DESC=	Use ImageMagick

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	client
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite3
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
RUN_DEPENDS=	memcached:${PORTSDIR}/databases/memcached
.endif

.if ${PORT_OPTIONS:MIMAGICK}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:${PORTSDIR}/graphics/pecl-imagick
.endif

.if ${PORT_OPTIONS:MAPC}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apc.so:${PORTSDIR}/www/pecl-APC
.elif ${PORT_OPTIONS:MEACCEL}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/eaccelerator.so:${PORTSDIR}/www/eaccelerator
.elif ${PORT_OPTIONS:MXCACHE}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xcache.so:${PORTSDIR}/www/xcache
.endif

pre-install:
	@${FIND} -s -d ${WRKSRC} -not -type d | ${SED} "s?${WRKSRC}?${MEDIAWIKIDIR}?g" >>${PLIST}
	@${ECHO} "@dir %%WWWDIR%%/vendor/zordius/lightncandy/specs/handlebars" >> ${PLIST}
	@${ECHO} "@dir %%WWWDIR%%/vendor/zordius/lightncandy/specs/mustache" >> ${PLIST}
	@${ECHO} @dir ${MEDIAWIKIDIR} >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MEDIAWIKIDIR}
	${CP} -r ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${MEDIAWIKIDIR}

.include <bsd.port.mk>
