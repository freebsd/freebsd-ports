# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	fluxbb
PORTVERSION=	1.5.10
CATEGORIES=	www
MASTER_SITES=	http://fluxbb.org/download/releases/${PORTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast and lightweight PHP-powered discussion board

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_WITH_PHP=	71 72 73

USES=		cpe php
SUB_FILES=	pkg-message
NO_BUILD=	yes

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL
MYSQL_USE=	PHP=mysql
PGSQL_USE=	PHP=pgsql
SQLITE_USE=	PHP=sqlite

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
