# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	ilias
PORTVERSION=	5.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Powerful, dynamic, PHP and MySQL based e-learning platform

LICENSE=	GPLv2

RUN_DEPENDS=	convert:graphics/ImageMagick \
		zip:archivers/zip \
		${UNZIP_CMD}:archivers/unzip \
		${LOCALBASE}/share/pear/PEAR.php:devel/pear \
		${LOCALBASE}/share/pear/Auth/Auth.php:security/pear-Auth \
		${LOCALBASE}/share/pear/MDB2.php:databases/pear-MDB2 \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:devel/pear-HTML_Template_IT
LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	ILIAS-eLearning
GH_PROJECT=	ILIAS

USES=		cpe jpeg
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
USE_PHP=	mysql session zlib gd pdf dom xsl pcre
WRKSRC=		${WRKDIR}/ILIAS-${PORTVERSION}
ILIASDIR=	www/ilias
ILIASDATADIR=	www/iliasdata
PLIST_SUB=	ILIASDATADIR=${ILIASDATADIR}
SUB_FILES=	pkg-message
SUB_LIST=	ILIASDATADIR=${ILIASDATADIR}

OPTIONS_DEFINE=		SCORM2004 Checker Mail
SCORM2004_USE=		php=json
Checker_RUN_DEPENDS=	${LOCALBASE}/share/pear/HTTP/Request.php:www/pear-HTTP_Request
Mail_RUN_DEPENDS=	${LOCALBASE}/share/pear/Mail.php:mail/pear-Mail

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ILIASDIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${ILIASDIR}?g" >> ${PLIST}
	@${ECHO} @dir ${ILIASDATADIR} >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${ILIASDATADIR}

.include <bsd.port.mk>
