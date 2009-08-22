# New ports collection makefile for:	phpsurveyor
# Date created:		21 March 2005
# Whom:	      		janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	limesurvey
PORTVERSION=	1.80
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}${PORTVERSION:S^.^^}_build6506_20090310

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A PHP-based survey building and runing system

USE_PHP=	mysql session mbstring pcre iconv gd ldap
WRKSRC=		${WRKDIR}/${PORTNAME}

PHPSURVEYORURL?=	${PORTNAME}
PHPSURVEYORDIR=		${WWWDOCROOT}/${PHPSURVEYORURL}

NO_BUILD=	yes

post-configure:
	@ ${SED} \
	-e 's#%%PREFIX%%#${PREFIX}#g' \
	-e 's#%%PHPSURVEYORURL%%#${PHPSURVEYORURL}#g' \
	-e 's#%%PHPSURVEYORDIR%%#${PHPSURVEYORDIR}#g' \

do-install:
	${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	${MKDIR} ${WWWDIR}/tmp
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} 755 ${WWWDIR}/tmp
	${CHMOD} 755 ${WWWDIR}/templates
	${CHMOD} 755 ${WWWDIR}/upload

post-install:
	@${FIND} -s -d ${WWWDIR} -type f -print | \
		${SED} -e "s#${PREFIX}/##g" >> ${TMPPLIST}
	@${FIND} -s -d ${WWWDIR} -type d  -print | \
		${SED} -E -e "s#${PREFIX}/#@dirrm #g" >> ${TMPPLIST}

.include <bsd.port.mk>
