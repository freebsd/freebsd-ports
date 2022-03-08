# Created by: Lars Eggert <lars.eggert@gmx.net>

PORTNAME=	crp
PORTVERSION=	20031012
PORTREVISION=	1
CATEGORIES=	www science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Oct-12-2003
DISTNAME=	CRP
EXTRACT_SUFX=	.tgz

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Automates the process of being the program chair of a conference

DEPRECATED=	Abandonware, last release in 2003 and upstream refers to PHP 4.x and is dead
EXPIRATION_DATE=2022-03-31

USES=	php:web
NO_BUILD=	yes
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

SPOOLDIR?=	/var/spool/conference

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${SED} -e 's|%%WWWDIR%%|${WWWDIR}|g; s|%%DISTNAME%%|${DISTNAME}|g' \
		${MASTERDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} -m 755 ${STAGEDIR}${WWWDIR} ${STAGEDIR}${SPOOLDIR}
	@${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/
	@${SED} -e 's#/var/www/html#${WWWDIR}#' \
	  ${WRKSRC}/Code/confHeader.inc > ${STAGEDIR}${WWWDIR}/Code/confHeader.inc

.include <bsd.port.mk>
