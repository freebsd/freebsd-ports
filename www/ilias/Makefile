PORTNAME=	ilias
PORTVERSION=	7.10
DISTVERSIONPREFIX=	v
CATEGORIES=	www education

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Powerful, dynamic, PHP and MySQL based e-learning platform

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/pear/Auth/Auth.php:security/pear-Auth@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:devel/pear-HTML_Template_IT@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/PEAR.php:devel/pear@${PHP_FLAVOR} \
		${UNZIP_CMD}:archivers/unzip \
		composer:devel/php-composer2 \
		sudo:security/sudo \
		zip:archivers/zip

USES=		cpe jpeg magick:6,run php
USE_GITHUB=	yes
GH_ACCOUNT=	ILIAS-eLearning
GH_PROJECT=	ILIAS
USE_PHP=	curl dom gd ldap fileinfo pcre pdf \
		pdo_mysql session simplexml soap \
		tokenizer xmlrpc xmlwriter xsl zlib

IGNORE_WITH_PHP=	80 81 82

CONFLICTS=	ilias6

NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	ILIASFILESDIR=${ILIASFILESDIR}

PLIST=		${WRKDIR}/plist
PLIST_SUB=	ILIASFILESDIR=${ILIASFILESDIR}

OPTIONS_DEFINE=	CHECKER MAIL SCORM2004

CHECKER_RUN_DEPENDS=	${LOCALBASE}/share/pear/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR}
MAIL_RUN_DEPENDS=	${LOCALBASE}/share/pear/Mail.php:mail/pear-Mail@${PHP_FLAVOR}
SCORM2004_USE=		PHP=json

ILIASDIR=	www/ilias
ILIASFILESDIR=	www/iliasfiles

EXTRA_FILES=	%%WWWDIR%%/Modules/Chatroom/chat/node_modules/.bin/mime \
		%%WWWDIR%%/Modules/Chatroom/chat/node_modules/.bin/uuid \
		%%WWWDIR%%/node_modules/.bin/_mocha \
		%%WWWDIR%%/node_modules/.bin/atob \
		%%WWWDIR%%/node_modules/.bin/errno \
		%%WWWDIR%%/node_modules/.bin/flat \
		%%WWWDIR%%/node_modules/.bin/gl-style-composite \
		%%WWWDIR%%/node_modules/.bin/gl-style-format \
		%%WWWDIR%%/node_modules/.bin/gl-style-migrate \
		%%WWWDIR%%/node_modules/.bin/gl-style-validate \
		%%WWWDIR%%/node_modules/.bin/he \
		%%WWWDIR%%/node_modules/.bin/image-size \
		%%WWWDIR%%/node_modules/.bin/js-yaml \
		%%WWWDIR%%/node_modules/.bin/lessc \
		%%WWWDIR%%/node_modules/.bin/loose-envify \
		%%WWWDIR%%/node_modules/.bin/mime \
		%%WWWDIR%%/node_modules/.bin/mocha \
		%%WWWDIR%%/node_modules/.bin/nanoid \
		%%WWWDIR%%/node_modules/.bin/needle \
		%%WWWDIR%%/node_modules/.bin/node-gyp-build \
		%%WWWDIR%%/node_modules/.bin/node-gyp-build-optional \
		%%WWWDIR%%/node_modules/.bin/node-gyp-build-test \
		%%WWWDIR%%/node_modules/.bin/node-which \
		%%WWWDIR%%/node_modules/.bin/opencollective-postinstall \
		%%WWWDIR%%/node_modules/.bin/pbf \
		%%WWWDIR%%/node_modules/.bin/rollup \
		%%WWWDIR%%/node_modules/.bin/semver \
		%%WWWDIR%%/node_modules/.bin/terser \
		%%WWWDIR%%/node_modules/.bin/uuid \
		%%WWWDIR%%/test/filter.test.js \
		%%WWWDIR%%/test/mainbar.test.js

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ILIASDIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d | ${SED} "s?${WRKSRC}?@dir ${ILIASDIR}?g" >> ${PLIST}
.for i in ${EXTRA_FILES}
	@${ECHO_CMD} ${i} >> ${PLIST}
.endfor
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
