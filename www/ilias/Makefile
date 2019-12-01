# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	ilias
PORTVERSION=	5.4.8
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Powerful, dynamic, PHP and MySQL based e-learning platform

LICENSE=	GPLv2

RUN_DEPENDS=	convert:graphics/ImageMagick6 \
		zip:archivers/zip \
		${UNZIP_CMD}:archivers/unzip \
		${LOCALBASE}/share/pear/PEAR.php:devel/pear@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/Auth/Auth.php:security/pear-Auth@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR} \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:devel/pear-HTML_Template_IT@${PHP_FLAVOR}
LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	ILIAS-eLearning
GH_PROJECT=	ILIAS

USES=		cpe jpeg php
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
USE_PHP=	pdo_mysql session zlib gd pdf dom xsl pcre simplexml
ILIASDIR=	www/ilias
ILIASDATADIR=	www/iliasdata
PLIST_SUB=	ILIASDATADIR=${ILIASDATADIR}
SUB_FILES=	pkg-message
SUB_LIST=	ILIASDATADIR=${ILIASDATADIR}

OPTIONS_DEFINE=		SCORM2004 CHECKER MAIL
SCORM2004_USE=		php=json
CHECKER_RUN_DEPENDS=	${LOCALBASE}/share/pear/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR}
MAIL_RUN_DEPENDS=	${LOCALBASE}/share/pear/Mail.php:mail/pear-Mail@${PHP_FLAVOR}

EXTRA_FILES=	%%WWWDIR%%/libs/composer/vendor/bin/generate_vcards \
		%%WWWDIR%%/libs/composer/vendor/bin/naturalselection \
		%%WWWDIR%%/libs/composer/vendor/bin/sabredav \
		%%WWWDIR%%/libs/composer/vendor/bin/vobject \
		%%WWWDIR%%/libs/composer/vendor/simplesamlphp/simplesamlphp/locales/no

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ILIASDIR}?g" >> ${PLIST}
.for i in ${EXTRA_FILES}
	@${ECHO_CMD} ${i} >> ${PLIST}
.endfor
	@${ECHO} @dir ${ILIASDATADIR} >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${ILIASDATADIR}

.include <bsd.port.mk>
