# New ports collection makefile for:	www/ilias
# Date created:				Oct 24, 2006
# Whom:					Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$

PORTNAME=	ilias
PORTVERSION=	4.0.6
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/1.%20ILIAS%204.0/ILIAS%20${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A poweful, dynamic, PHP and MySQL based e-learning platform

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		zip:${PORTSDIR}/archivers/zip \
		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/share/pear/PEAR.php:${PORTSDIR}/devel/pear \
		${LOCALBASE}/share/pear/Auth/Auth.php:${PORTSDIR}/security/pear-Auth \
		${LOCALBASE}/share/pear/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:${PORTSDIR}/devel/pear-HTML_Template_IT
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

CONFLICTS=	ilias-3.[0-9].*

NO_BUILD=		yes
PLIST=			${WRKDIR}/plist
SUB_FILES=		pkg-message
USE_MYSQL=		yes
DEFAULT_MYSQL_VER=	50
USE_PHP=		mysql session zlib gd pdf dom xsl pcre
DEFAULT_PHP_VER=	5
WRKSRC=			${WRKDIR}/ilias
ILIASDIR=		www/ilias
ILIASDATADIR=		www/iliasdata
PORTDOCS=*
PLIST_SUB=	ILIASDATADIR=${ILIASDATADIR}
SUB_FILES=	pkg-message
SUB_LIST=	ILIASDATADIR=${ILIASDATADIR}

OPTIONS=	SCORM2004 "Using SCORM2004 support" off	\
		Checker "Link Checker" off \
		Mail "Internet compliant E-Mail addresses" off

.include <bsd.port.pre.mk>

.if defined(WITH_SCORM2004)
USE_PHP+=	json
.endif

.if defined(WITH_Checker)
RUN_DEPENDS+=	 ${LOCALBASE}/share/pear/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
.endif

.if defined(WITH_Mail)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ILIASDIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${ILIASDIR}?g" >> ${PLIST}
	@${ECHO} @dirrm ${ILIASDATADIR} >> ${PLIST}

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

.if !defined(NOPORTDOCS)
	@cd ${WRKDIR}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
