# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	fluxbb
PORTVERSION=	1.5.9
CATEGORIES=	www
MASTER_SITES=	http://fluxbb.org/download/releases/${PORTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast and lightweight PHP-powered discussion board

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

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
