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
DEFAULT_VERSIONS+=	php=5
CONFLICTS=	AutoIndex-1*
NO_BUILD=	yes

INSTALLDIR?=	${WWWDIR}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,}

post-extract:
	${MV} ${WRKSRC}/config.php ${WRKSRC}/config.php.sample
	${MV} ${WRKSRC}/.htpasswd.autoindex ${WRKSRC}/.htpasswd.autoindex.sample

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR})

.include <bsd.port.mk>
