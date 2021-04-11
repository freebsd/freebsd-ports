# Created by: Gerrit Beine <tux@pinguru.net>

PORTNAME=	mediawiki
PORTVERSION=	1.35.2
CATEGORIES=	www
MASTER_SITES=	http://releases.wikimedia.org/mediawiki/${PORTVERSION:R}/
PKGNAMESUFFIX=	135${PHP_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Wiki engine used by Wikipedia

LICENSE=	GPLv2

CONFLICTS=	mediawiki13[1-4]-[0-9]*

USES=		php:flavors shebangfix
SHEBANG_FILES=	maintenance/dev/*.sh \
		maintenance/postgres/*.pl \
		maintenance/storage/make-blobs \
		includes/shell/limit.sh
SHEBANG_LANG=	hhvm
hhvm_OLD_CMD=	/usr/bin/hhvm
hhvm_CMD=	${LOCALBASE}/bin/hhvm # not installed by anything yet
USE_PHP=	ctype dom fileinfo filter hash iconv intl json mbstring openssl \
		pcre readline session xml xmlreader zlib
MEDIAWIKIDIR?=	www/mediawiki

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist

SUB_FILES=	pkg-message
SUB_LIST=	MEDIAWIKIDIR=${PREFIX}/${MEDIAWIKIDIR}

OPTIONS_DEFINE=	LDAP MEMCACHED IMAGICK SOCKETS
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL SOCKETS

MEMCACHED_DESC=	Use memcached
IMAGICK_DESC=	Use ImageMagick
SOCKETS_DESC=	Use sockets

MYSQL_USES=	mysql
MYSQL_USE=	php=mysqli
PGSQL_USE=	php=pgsql
SQLITE_USE=	php=sqlite3
LDAP_USE=	php=ldap
SOCKETS_USE=	php=sockets

MEMCACHED_RUN_DEPENDS=	memcached:databases/memcached
IMAGICK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:graphics/pecl-imagick@${PHP_FLAVOR}

pre-install:
	@${FIND} -s -d ${WRKSRC} -not -type d | ${SED} "s?${WRKSRC}?${MEDIAWIKIDIR}?g" >>${PLIST}
	@${ECHO} "@dir %%WWWDIR%%/cache" >> ${PLIST}
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO} "@mode 0755" >> ${PLIST}
	@${ECHO} "@dir %%WWWDIR%%/images" >> ${PLIST}
	@${ECHO} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO} @dir ${MEDIAWIKIDIR} >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MEDIAWIKIDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MEDIAWIKIDIR}

.include <bsd.port.mk>
