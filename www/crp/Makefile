# New ports collection makefile for:	crp
# Date created:				June 01 2004
# Whom:					Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	crp
PORTVERSION=	20031012
CATEGORIES=	www science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	CRP
EXTRACT_SUFX=	.tgz

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Automates the process of being the program chair of a conference

USE_PHP=	yes
WANT_PHP_WEB=	yes
NO_BUILD=	yes

WWWDIR?=	${PREFIX}/www
SPOOLDIR?=	/var/spool/conference

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${SED} -e 's|%%WWWDIR%%|${WWWDIR}|g; s|%%DISTNAME%%|${DISTNAME}|g' \
		${MASTERDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} -m 755 ${WWWDIR} ${SPOOLDIR}
	@${CP} -R ${WRKSRC} ${WWWDIR}
	@${SED} -e 's#/var/www/html#${PREFIX}/www/${DISTNAME}#' \
	  ${WRKSRC}/Code/confHeader.inc > ${WWWDIR}/${DISTNAME}/Code/confHeader.inc
	@${CHOWN} -R ${WWWOWN}:${WWWGROUP} ${WWWDIR}/${DISTNAME} ${SPOOLDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
