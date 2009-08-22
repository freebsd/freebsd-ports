# New ports collection makefile for:	AutoIndex
# Date created:				17 December 2004
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	AutoIndex
PORTVERSION=	2.2.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}%20PHP%20Script%202.x/${PORTNAME}%20PHP%20${PORTVERSION}

MAINTAINER=	danger@FreeBSD.org
COMMENT=	PHP 5.x script that makes a table that lists the files in a directory

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_DOS2UNIX=	yes
USE_PHP=	session
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4
CONFLICTS=	AutoIndex-1*
LATEST_LINK=	AutoIndex2
NO_BUILD=	yes

PLIST_SUB+=	INSTALLDIR=${WWWDIR:S,^${PREFIX}/,,}

pre-fetch:
.if !defined(INSTALLDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define INSTALLDIR to override default of '${WWWDIR}'."
	@${ECHO_MSG} ""
.endif

INSTALLDIR?=	${WWWDIR}

do-install:
	@${MKDIR} ${INSTALLDIR}
	@${CP} -R ${WRKSRC}/* ${INSTALLDIR}
	@${CP} -p ${WRKSRC}/.htpasswd.autoindex ${INSTALLDIR}/.htpasswd.autoindex-dist
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${INSTALLDIR}
	@${CHMOD} -R 644 ${INSTALLDIR}/* ${INSTALLDIR}/.htpasswd.autoindex-dist
	@${CHMOD} 755 ${INSTALLDIR}/classes ${INSTALLDIR}/index_icons ${INSTALLDIR}/languages ${INSTALLDIR}/templates
	@${CHMOD} 755 ${INSTALLDIR}/index_icons/* ${INSTALLDIR}/templates/default ${INSTALLDIR}/templates/simple_image_gallery
	@${CHMOD} 664 ${INSTALLDIR}/config.php
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
