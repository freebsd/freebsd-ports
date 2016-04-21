# Created by: ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	plexWatchWeb
PORTVERSION=	1.5.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Web front-end for plexWatch

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	multimedia/plexwatch>=0.1.6:multimedia/plexwatch

USE_PHP=	curl json session simplexml sqlite3

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}

USE_GITHUB=	yes
GH_ACCOUNT=	ecleese
GH_TAGNAME=	0d05556
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/config
	${RM} -r ${WRKSRC}/config
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \*  ${STAGEDIR}${WWWDIR}/)

.include <bsd.port.mk>
