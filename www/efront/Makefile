# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	efront
DISTVERSION=	3.6.14
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}learning/${PORTNAME}learning/eFront%20v3.6.14/
DISTNAME=	${PORTNAME}_${PORTVERSION}_build18016_community

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Elearning and Human Capital Development platform

USES=		cpe zip
CPE_VENDOR=	efrontlearning
USE_PHP=	mbstring zip iconv zlib spl ldap
EFRONT_FILES=	CHANGELOG.txt index.php INSTALL.txt \
		LICENSE.txt  README.txt
EFRONT_DIRS=	libraries PEAR \
		upload www backups

NO_BUILD=	yes
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for i in ${EFRONT_FILES}
	@cd ${WRKDIR} && ${CP} ${i} ${STAGEDIR}${WWWDIR}
.endfor
.for i in ${EFRONT_DIRS}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}
.endfor
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
