# New ports collection makefile for:	phpsurveyor
# Date created:		21 March 2005
# Whom:	      		janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	phpsurveyor
PORTVERSION=	0.98
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0_98_final

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	A PHP-based survey building and runing system

USE_PHP=	mysql session
WRKSRC=		${WRKDIR}
USE_ZIP=	yes

#User-configurable variables
WWWDOCROOT?=	www/data
PHPSURVEYORURL?=	phpsurveyor
WWWOWN?=	www
WWWGRP?=	www
#
# End of user-configurable variables.

# Set/override/append to variables from bsd.port.mk:
#
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	PHPSURVEYORDIR=${PHPSURVEYORDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

# Set custom variables:
#
PHPSURVEYORDIR=	${WWWDOCROOT}/${PHPSURVEYORURL}

post-configure:
	@ ${SED} \
	-e 's#%%PREFIX%%#${PREFIX}#g' \
	-e 's#%%PHPSURVEYORURL%%#${PHPSURVEYORURL}#g' \
	-e 's#%%PHPSURVEYORDIR%%#${PHPSURVEYORDIR}#g' \
	pkg-message > ${PKGMESSAGE}

do-install:
	${MKDIR} -m 0755 ${PREFIX}/${PHPSURVEYORDIR}
	cd ${WRKSRC} && ${FIND} * \( -name tmp -a -prune \) -o -print \
	  | ${TAR} cTf - - | ${TAR} xUCf ${PREFIX}/${PHPSURVEYORDIR} -
	${MKDIR} ${PREFIX}/${PHPSURVEYORDIR}/tmp
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPSURVEYORDIR}
	${CHMOD} 755 ${PREFIX}/${PHPSURVEYORDIR}/tmp

post-install:
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
