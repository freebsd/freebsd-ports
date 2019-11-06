# $FreeBSD$

PORTNAME=	sabredav
PORTVERSION=	3.2.2
CATEGORIES=	www
MASTER_SITES=	https://github.com/fruux/sabre-dav/releases/download/${PORTVERSION}/

MAINTAINER=	meyser@xenet.de
COMMENT=	WebDav, CalDav and Carddav Server/Framework written in PHP

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL

USES=			cpe php zip
CPE_VENDOR=		fruux
USE_PHP=		dom simplexml mbstring pcre spl ctype iconv xmlwriter

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

do-install:
	  ${MKDIR} ${STAGEDIR}/${WWWDIR}
	  (cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR} )

.include <bsd.port.mk>
