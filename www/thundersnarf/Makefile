PORTNAME=	thundersnarf
PORTVERSION=	1.3
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.tracanelli.com.br/l/dev/thunder/ \
		LOCAL/jmelo

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Web reporting and trending analysis for Thunder Cache Pro
WWW=		http://www.thundercache.com.br

DEPRECATED=	Depends on deprecated php80
EXPIRATION_DATE=	2023-12-12

LIB_DEPENDS+=	libcurl.so:ftp/curl

USES=		tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	OWNER=${WWWOWN} GROUP=${WWWGRP}

OPTIONS_DEFINE=	APACHE PHP PGSQL DOCS
OPTIONS_DEFAULT=APACHE PHP PGSQL

APACHE_DESC=	Install apache for reporting viewing
PGSQL_DESC=	Install PostgreSQL (report data storing)
PHP_DESC=	Install PHP for reporting generating

APACHE_USES=		apache:run
PGSQL_USES=		pgsql
PGSQL_VARS=	WANT_PGSQL=server
PHP_USES=	php
# php spl extension is required but it's statically linked in default php
PHP_USE=	PHP=curl,bcmath,pdo,mcrypt,session,pgsql,dom,xmlrpc,ctype,simplexml,soap
PHP_VARS=	IGNORE_WITH_PHP="81 82 83"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP}
.  if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql pgsql
.  endif
.endif

post-extract:
	@${RM} ${WRKSRC}/protected/data/bin/._thundersnarf

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/protected/data/bin/thundersnarf* \
		${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README.pt_BR

.include <bsd.port.mk>
