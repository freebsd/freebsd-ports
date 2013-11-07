# $FreeBSD$

PORTNAME=	owncloud
PORTVERSION=	5.0.13
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3

BUILD_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PHP=	ctype curl dom fileinfo filter gd hash iconv json ldap mbstring \
		mysql openssl pdo pdo_mysql pdo_sqlite session simplexml \
		sqlite3 xml xmlreader xsl wddx zip zlib
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5

WWWDOCROOT?=	www

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}

post-install:
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type f -print | \
		${SED} -e "s#^\.#${WWWDIR_REL}#" >> ${TMPPLIST}
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type d  -print | \
		${SED} -e "s#^\.#@unexec rmdir ${WWWDIR_REL}#" >> ${TMPPLIST}

.include <bsd.port.mk>
