# $FreeBSD$

PORTNAME=	sabredav
PORTVERSION=	2.0.3
CATEGORIES=	www
MASTER_SITES=	https://github.com/fruux/sabre-dav/releases/download/${PORTVERSION}/

MAINTAINER=	meyser@xenet.de
COMMENT=	WebDav, CalDav and Carddav Server/Framework written in PHP

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=		MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL

MYSQL_DESC=		Install mysql support
PGSQL_DESC=		Install postgresql support
SQLITE_DESC=		Install sqlite support

OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE

USES=			zip
USE_PHP=		dom simplexml mbstring ctype iconv

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=		pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=		pdo_pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=		pdo_sqlite
.endif

WRKSRC=		${WRKDIR}/SabreDAV

NO_BUILD=	yes

USE_PHP=	yes

do-install:
	  ${MKDIR} ${STAGEDIR}/${WWWDIR}
	  (cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR} )

.include <bsd.port.mk>
