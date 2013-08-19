# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	claroline
PORTVERSION=	1.11.8
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Claroline/Claroline_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source eLearning and eWorking platform

NO_BUILD=	yes
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message

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

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >>${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
