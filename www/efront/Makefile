# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	efront
DISTVERSION=	3.6.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}learning/${PORTNAME}learning/eFront%20v3.6.6/
DISTNAME=	${PORTNAME}_${PORTVERSION}_build8242

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Elearning and Human Capital Development platform

USES=		zip
USE_PHP=	mbstring zip iconv zlib spl ldap
EFRONT_FILES=	CHANGELOG.txt index.php INSTALL.txt \
		LICENSE.txt  README.txt
EFRONT_DIRS=	libraries PEAR \
		upload www backups

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for i in ${EFRONT_FILES}
	@cd ${WRKDIR} && ${CP} ${i} ${STAGEDIR}${WWWDIR}
.endfor
.for i in ${EFRONT_DIRS}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
