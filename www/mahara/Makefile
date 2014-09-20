# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mahara
PORTVERSION=	1.9.2
CATEGORIES=	www
MASTER_SITES=	http://launchpad.net/${PORTNAME}/1.9/${PORTVERSION}/+download/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open source ePortfolio system

LICENSE=	GPLv3

USES=		tar:bzip2
USE_PHP=	session json curl xml xmlrpc openssl simplexml

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
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MAHARADIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MAHARADIR}?g" >> ${PLIST}
	@${ECHO} @dirrmtry ${MAHARADATADIR} >> ${PLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/${MAHARADATADIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R a+w ${STAGEDIR}${PREFIX}/${MAHARADATADIR}

.include <bsd.port.mk>
