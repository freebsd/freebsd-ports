# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	ilias
PORTVERSION=	3.10.14
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/3.%20ILIAS%203.10/ILIAS%20${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Powerful, dynamic, PHP and MySQL based e-learning platform

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		zip:${PORTSDIR}/archivers/zip \
		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/share/pear/PEAR.php:${PORTSDIR}/devel/pear \
		${LOCALBASE}/share/pear/Auth/Auth.php:${PORTSDIR}/security/pear-Auth \
		${LOCALBASE}/share/pear/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:${PORTSDIR}/devel/pear-HTML_Template_IT
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

CONFLICTS=	ilias-4.[0-9].*

DEPRECATED=	Obsolete stable release
EXPIRATION_DATE=2013-04-30

LATEST_LINK=		ilias3
NO_BUILD=		yes
SUB_FILES=		pkg-message
USE_PHP=		mysql session zlib gd pdf dom xsl pcre
WRKSRC=			${WRKDIR}/ilias3
ILIASDATADIR=		www/iliasdata
PORTDOCS=*
PLIST_SUB=	ILIASDATADIR=${ILIASDATADIR}
SUB_FILES=	pkg-message
SUB_LIST=	ILIASDATADIR=${ILIASDATADIR}

OPTIONS_DEFINE=	SCORM2004 CHECKER MAIL

SCORM2004_DESC=		Using SCORM2004 support
CHECKER_DESC=		Link Checker
MAIL_DESC=		Mail Support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSCORM2004}
USE_PHP+=	json
.endif

.if ${PORT_OPTIONS:MCHECKER}
RUN_DEPENDS+=	 ${LOCALBASE}/share/pear/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
.endif

.if ${PORT_OPTIONS:MMAIL}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

post-extract:
	@cd ${WRKSRC} && ${MV} docs ${WRKDIR}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${INSTALL} -d ${PREFIX}/${ILIASDATADIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${ILIASDATADIR}
	@${CHMOD} -R 755 ${PREFIX}/${ILIASDATADIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >>${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${ILIASDATADIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${PREFIX}/${ILIASDATADIR}' >>${TMPPLIST}

.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKDIR}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
