PORTNAME=	mediawiki
PORTVERSION=	1.35.14
CATEGORIES=	www
MASTER_SITES=	http://releases.wikimedia.org/mediawiki/${PORTVERSION:R}/
PKGNAMESUFFIX=	135${PHP_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Wiki engine used by Wikipedia
WWW=		https://www.mediawiki.org/

LICENSE=	GPLv2

DEPRECATED=	Upstream reached EOL on 2023-12-21
EXPIRATION_DATE=	2024-03-31

USES=		cpe php:flavors shebangfix
USE_PHP=	ctype dom fileinfo filter iconv intl mbstring \
		readline session xml xmlreader zlib

SHEBANG_FILES=	maintenance/dev/*.sh \
		maintenance/postgres/*.pl \
		maintenance/storage/make-blobs \
		includes/shell/limit.sh
SHEBANG_LANG=	hhvm
hhvm_OLD_CMD=	/usr/bin/hhvm
hhvm_CMD=	${LOCALBASE}/bin/hhvm # not installed by anything yet

CONFLICTS=	mediawiki13[8-9] mediawiki14[0-9]

NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	MEDIAWIKIDIR=${PREFIX}/${MEDIAWIKIDIR}

MEDIAWIKIDIR?=	www/mediawiki

PLIST=		${WRKDIR}/plist

OPTIONS_DEFINE=	LDAP MEMCACHED IMAGICK SOCKETS
OPTIONS_DEFAULT=	MYSQL SOCKETS
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE

IMAGICK_DESC=	Use ImageMagick
MEMCACHED_DESC=	Use memcached
SOCKETS_DESC=	Use sockets

IMAGICK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:graphics/pecl-imagick@${PHP_FLAVOR}
LDAP_USE=	php=ldap
MEMCACHED_RUN_DEPENDS=	memcached:databases/memcached
MYSQL_USES=	mysql
MYSQL_USE=	php=mysqli
PGSQL_USE=	php=pgsql
SOCKETS_USE=	php=sockets
SQLITE_USE=	php=sqlite3

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
