# New ports collection makefile for:	phpsurveyor
# Date created:		21 March 2005
# Whom:	      		janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	limesurvey
PORTVERSION=	1.90
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/1._LimeSurvey_stable/${PORTVERSION}+/
DISTNAME=	${PORTNAME}${PORTVERSION:S^.^^}plus-build9321-20101023

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A PHP-based survey building and runing system

USE_PHP=	mysql session mbstring pcre iconv gd ldap ctype

WWWDOCROOT?=		www
PHPSURVEYORURL?=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPSURVEYORURL="${PHPSURVEYORURL}" \
		PHPSURVEYORDIR="${PHPSURVEYORDIR}"

PHPSURVEYORDIR=	${WWWDOCROOT}/${PHPSURVEYORURL}

do-install:
	${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	${MKDIR} ${WWWDIR}/tmp
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} 755 ${WWWDIR}/tmp
	${CHMOD} 755 ${WWWDIR}/templates
	${CHMOD} 755 ${WWWDIR}/upload

post-install:
	@${CAT} ${PKGMESSAGE}
	@${FIND} -s -d ${WWWDIR} -type f -print | \
		${SED} -e "s#${PREFIX}/##g" >> ${TMPPLIST}
	@${FIND} -s -d ${WWWDIR} -type d  -print | \
		${SED} -E -e "s#${PREFIX}/#@dirrm #g" >> ${TMPPLIST}

.include <bsd.port.mk>
