# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	claroline
PORTVERSION=	1.11.10.1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Claroline/Claroline_1.11.10
DISTNAME=	${PORTNAME}-1.11.10-1

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source eLearning and eWorking platform

LICENSE=	GPLv2

IGNORE_WITH_PHP=	70 71 72

USES=		cpe php

NO_BUILD=	yes
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message
PLIST=		${WRKDIR}/plist
CLARODIR=	www/claroline

OPTIONS_DEFINE=		LDAP GD SSL
OPTIONS_DEFAULT=	GD

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MSSL}
USE_PHP+=	openssl
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${CLARODIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${CLARODIR}?g" >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}' >>${PLIST}

.include <bsd.port.mk>
