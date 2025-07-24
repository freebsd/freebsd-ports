PORTNAME=	ilias
DISTVERSIONPREFIX=	v
DISTVERSION=	9.12
CATEGORIES=	www education
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Powerful, dynamic, PHP and MySQL based e-learning platform
WWW=		https://www.ilias.de

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/pear/Auth/Auth.php:security/pear-Auth@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:devel/pear-HTML_Template_IT@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/PEAR.php:devel/pear@${PHP_FLAVOR} \
		${PECL_PKGNAMEPREFIX}imagick>=0:graphics/pecl-imagick@${PHP_FLAVOR} \
		${UNZIP_CMD}:archivers/unzip \
		composer:devel/php-composer@${PHP_FLAVOR} \
		sudo:security/sudo \
		zip:archivers/zip

USES=		cpe jpeg magick:7,run php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	ILIAS-eLearning
GH_PROJECT=	ILIAS
USE_PHP=	curl dom gd ldap fileinfo iconv \
		pdo_mysql session simplexml soap \
		tokenizer xmlrpc xmlwriter xmlreader \
		xsl zip zlib

CONFLICTS=	ilias6

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	ILIASFILESDIR=${ILIASFILESDIR}

PLIST=		${WRKDIR}/plist
PLIST_SUB=	ILIASFILESDIR=${ILIASFILESDIR}

OPTIONS_DEFINE=	CHECKER MAIL

CHECKER_RUN_DEPENDS=	${LOCALBASE}/share/pear/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR}
MAIL_RUN_DEPENDS=	${LOCALBASE}/share/pear/Mail.php:mail/pear-Mail@${PHP_FLAVOR}

ILIASDIR=	www/ilias
ILIASFILESDIR=	www/iliasfiles

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ILIASDIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d | ${SED} "s?${WRKSRC}?@dir ${ILIASDIR}?g" >> ${PLIST}
	@${ECHO_CMD} "${ILIASFILESDIR}/config.json" >> ${PLIST}
	@${ECHO_CMD} @dir ${ILIASFILESDIR} >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${ILIASFILESDIR}
	@${CP} ${FILESDIR}/config.json ${STAGEDIR}${PREFIX}/${ILIASFILESDIR}

.include <bsd.port.mk>
