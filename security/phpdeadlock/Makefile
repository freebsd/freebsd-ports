# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpdeadlock
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	SF/${PORTNAME}/Deadlock/${PORTVERSION}%20Stable
DISTNAME=	Deadlock-${PORTVERSION}-Stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based user authentication/password protection system

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

WRKSRC=		${WRKDIR}/Deadlock-1.01
DLURL?=		${PORTNAME}
DLDIR=		www/${DLURL}
PORTDOCS=	CHANGES.txt COPYING.txt UPGRADE.txt

USES=		apache:run,2.2+ dos2unix
USE_PHP=	mysql session ctype pcre
NO_BUILD=	yes
NO_ARCH=	yes

IGNORE_WITH_PHP=	71 72 73

SUB_FILES=	pkg-message
SUB_LIST=	DLURL=${DLURL} DLDIR=${DLDIR}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKDIR} && ${MV} "Deadlock v1.01" Deadlock-1.01

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -exec ${RM} {} \;

do-install:
	@cd ${WRKSRC}/deadlock && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
