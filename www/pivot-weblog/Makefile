# New ports collection makefile for:	pivot-weblog
# Date created:		2006-08-01
# Whom:			Hans Fredrik Nordhaug <hans@nordhaug.priv.no>
#
# $FreeBSD$
#

PORTNAME=	pivot-weblog
PORTVERSION=	1.40.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	pivot_1403_full

MAINTAINER=	hans@nordhaug.priv.no
COMMENT=	A web-based tool to help you maintain weblogs (or other dynamic sites)

USE_ZIP=	YES
USE_PHP=	pcre session
NO_BUILD=	YES
WANT_PHP_WEB=	YES

BLOGURL?=	weblog
WWWDOCROOT?=	www
BLOGDIR?=	${WWWDOCROOT}/${BLOGURL}

SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	BLOGURL=${BLOGURL} BLOGDIR=${BLOGDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PLIST_SUB=	BLOGDIR=${BLOGDIR}

post-extract:
	@${MKDIR} ${WRKDIR}/pivot/default-data/
.for OBJECT in pivot/db pivot/templates pivot/pv_cfg_settings.php pivot/pv_cfg_weblogs.php
	@${MV} ${WRKDIR}/${OBJECT} ${WRKDIR}/pivot/default-data/
.endfor
	@${ECHO_MSG}
	@${ECHO_MSG} "You may change the data/weblog directory with the option BLOGURL"
	@${ECHO_MSG} "Set NOPORTDOCS if you do not need any documentation"
	@${ECHO_MSG}

do-install:
# Installing docs
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILES in README.txt example.htaccess
	@${CP} -v ${WRKDIR}/${FILES} ${DOCSDIR}
.endfor
.endif
# Actually installing the runtime/PHP files
.for DIR in images archives
	@${MKDIR} ${PREFIX}/${BLOGDIR}/${DIR}
.endfor
.for DIR in pivot extensions
	@${CP} -Rv ${WRKDIR}/${DIR} ${PREFIX}/${BLOGDIR}/
.endfor

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
