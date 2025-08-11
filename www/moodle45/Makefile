PORTNAME=	moodle
PORTVERSION=	4.5.6
CATEGORIES=	www education
MASTER_SITES=	https://packaging.moodle.org/stable405/ \
		LOCAL/wen
PKGNAMESUFFIX=	${PKGORIGIN:T:S/moodle//}${PHP_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Course management system based on social constructionism
WWW=		https://www.moodle.org/

LICENSE=	GPLv3

CONFLICTS=	moodle44-4.4.[0-9]* moodle50-5.0.[0-9]*

USES=		cpe php:flavors tar:tgz
USE_PHP=	ctype curl dom exif fileinfo filter gd \
		iconv intl mbstring opcache \
		session simplexml soap sodium tokenizer \
		xml xmlreader xmlrpc zip zlib

WRKSRC=		${WRKDIR}/moodle

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL
OPTIONS_DEFINE=		LDAP
OPTIONS_DEFAULT=	MYSQL

MYSQL_USES=	mysql
MYSQL_USE=	php=mysqli
PGSQL_USE=	php=pgsql
LDAP_USE=	php=ldap

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MOODLEDIR=${MOODLEDIR} \
		MOODLEDATADIR=${MOODLEDATADIR}

MOODLEDIR?=	www/moodle
MOODLEDATADIR?=	moodledata

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${ECHO} @dir ${MOODLEDATADIR} >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

#  Here for safety I do not set moodle diretory 0755 permission
#  It require user write config.php manually then.
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MOODLEDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${MOODLEDIR}?g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${MOODLEDIR}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${MOODLEDATADIR}

.include <bsd.port.mk>
