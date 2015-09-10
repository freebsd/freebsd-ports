# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	ilias
PORTVERSION=	5.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Powerful, dynamic, PHP and MySQL based e-learning platform

LICENSE=	GPLv2

USE_GITHUB=     yes
GH_ACCOUNT=     ILIAS-eLearning
GH_PROJECT=     ILIAS

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		zip:${PORTSDIR}/archivers/zip \
		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/share/pear/PEAR.php:${PORTSDIR}/devel/pear \
		${LOCALBASE}/share/pear/Auth/Auth.php:${PORTSDIR}/security/pear-Auth \
		${LOCALBASE}/share/pear/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:${PORTSDIR}/devel/pear-HTML_Template_IT
LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USES=		cpe jpeg
NO_BUILD=		yes
PLIST=			${WRKDIR}/plist
SUB_FILES=		pkg-message
USE_PHP=		mysql session zlib gd pdf dom xsl pcre
WRKSRC=			${WRKDIR}/ILIAS-${PORTVERSION}
ILIASDIR=		www/ilias
ILIASDATADIR=		www/iliasdata
PLIST_SUB=	ILIASDATADIR=${ILIASDATADIR}
SUB_FILES=	pkg-message
SUB_LIST=	ILIASDATADIR=${ILIASDATADIR}

OPTIONS_DEFINE=	SCORM2004 Checker Mail

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSCORM2004}
USE_PHP+=	json
.endif

.if ${PORT_OPTIONS:MChecker}
RUN_DEPENDS+=	 ${LOCALBASE}/share/pear/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
.endif

.if ${PORT_OPTIONS:MMail}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

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
