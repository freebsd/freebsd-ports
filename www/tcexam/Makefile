PORTNAME=	tcexam
PORTVERSION=	16.5.0
CATEGORIES=	www education
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source system for electronic exams
WWW=		https://www.tcexam.org/

LICENSE=	GPLv3

USES=		cpe php:flavors tar:tgz
USE_PHP=	curl gd xml

CPE_VENDOR=	tecnick

USE_GITHUB=	yes
GH_ACCOUNT=	tecnickcom

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

MYSQL_USE=	php=mysqli
PGSQL_USE=	php=pgsql

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	TCDIR=${TCDIR}

TCDIR?=		www/tcexam

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}

	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${TCDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d | ${SED} "s?${WRKSRC}?@dir ${TCDIR}?g" >> ${PLIST}

	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${TCDIR}

.include <bsd.port.mk>
