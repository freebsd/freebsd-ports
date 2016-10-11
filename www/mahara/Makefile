# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mahara
PORTVERSION=	16.04.3
CATEGORIES=	www
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open source ePortfolio system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		cpe tar:bzip2
USE_PHP=	dom gd session json curl xml xmlrpc openssl simplexml \
		mcrypt zip

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL
MYSQL_USE=	PHP=mysql
PGSQL_USE=	PHP=pgsql

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MAHARADIR=${MAHARADIR} \
		MAHARADATADIR=${MAHARADATADIR}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/htdocs

MAHARADIR?=	www/mahara
MAHARADATADIR?=	www/maharadata

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MAHARADIR}?g" >> ${PLIST}
	@${ECHO_CMD} "@dir(${WWWOWN},${WWWGRP},755) ${MAHARADATADIR}" >> ${PLIST}
	@${ECHO_CMD} "@dir %%WWWDIR%%/lib/tests" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MAHARADATADIR}

.include <bsd.port.mk>
