# New ports collection makefile for:   eFront
# Date created:		07 June 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	efront
DISTVERSION=	3.6.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}learning/${PORTNAME}learning/eFront%20v3.6.6/
DISTNAME=	${PORTNAME}_${PORTVERSION}_build8242

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Elearning and Human Capital Development platform

USE_ZIP=	YES
USE_PHP=	mbstring zip iconv zlib spl ldap
EFRONT_FILES=	CHANGELOG.txt index.php INSTALL.txt \
		LICENSE.txt  README.txt
EFRONT_DIRS=	libraries PEAR \
		upload www backups

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
do-install:
	@if [ ! -f ${WWWDIR} ]; then \
		${MKDIR} ${WWWDIR} ; fi
.for i in ${EFRONT_FILES}
	@cd ${WRKDIR} && ${CP} ${i} ${WWWDIR}
.endfor
.for i in ${EFRONT_DIRS}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
