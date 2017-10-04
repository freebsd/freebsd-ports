# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	freeway
PORTVERSION=	1.4.2.197
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}-ecom/Freeway/${PORTVERSION}%20Sathish
DISTNAME=	${PORTNAME}_${PORTVERSION:S,.,_,g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced Open Source eCommerce Platform

USES=		shebangfix php
SHEBANG_FILES=	admin/htmlarea/plugins/SpellChecker/spell-check-logic.cgi
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
