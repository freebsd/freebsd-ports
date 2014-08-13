# Created by: Daniel Gerzo <danger@rulez.sk>
# $FreeBSD$

PORTNAME=	AutoIndex
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}%20PHP%20Script%202.x/${PORTNAME}%20PHP%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP 5.x script that put a directory listing into a table

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		dos2unix
USE_PHP=	session
DEFAULT_VERSIONS=	php=5
CONFLICTS=	AutoIndex-1*
LATEST_LINK=	AutoIndex2
NO_BUILD=	yes

INSTALLDIR?=	${WWWDIR}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,}

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	cd ${WRKSRC} && ${MV} config.php config.php.sample
	cd ${WRKSRC} && ${MV} .htpasswd.autoindex .htpasswd.autoindex.sample
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}

.include <bsd.port.mk>
