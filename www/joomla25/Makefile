# Created by: Francisco Cabrita <include@npf.pt.freebsd.org>
# $FreeBSD$

PORTNAME=	joomla
PORTVERSION=	2.5.11
CATEGORIES=	www
PKGNAMESUFFIX=	2

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Dynamic web content management system (CMS)

LICENSE=	GPLv2

CONFLICTS=	joomla-1.*.*

GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}-cms
GH_COMMIT=	6897f9b

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES=	pkg-message

USE_GITHUB=	yes
USE_MYSQL=	yes
USE_PHP=	gd json mbstring mysql mysqli pcre pdf session simplexml xml zip zlib

WANT_PHP_WEB=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${WWWDIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} . \! -type d -and \! \( -name .gitignore -or -name LICENSE.txt \) \
			-exec ${INSTALL_DATA} {} ${WWWDIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
