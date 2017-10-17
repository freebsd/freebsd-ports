# $FreeBSD$

PORTNAME=	thundersnarf
PORTVERSION=	1.3
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.tracanelli.com.br/l/dev/thunder/ \
		LOCAL/jmelo

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Web reporting and trending analysis for Thunder Cache Pro

OPTIONS_DEFINE=	APACHE PHP PGSQL DOCS
OPTIONS_DEFAULT=APACHE PHP PGSQL
APACHE_DESC=	Install apache for reporting viewing
PHP_DESC=	Install PHP for reporting generating
PGSQL_DESC=	Install PostgreSQL (report data storing)

USES=		tar:bzip2

PHP_USES=	php

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	OWNER=${WWWOWN} GROUP=${WWWGRP}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
WANT_PGSQL=	server
.endif

.if ${PORT_OPTIONS:MPHP}
USE_PHP+=	curl pcre bcmath pdo mcrypt hash session pgsql spl dom xmlrpc ctype openssl simplexml soap json
.  if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql pgsql
.  endif
.endif

LIB_DEPENDS+=	libcurl.so:ftp/curl

SUB_FILES=	pkg-message

post-extract:
	# Present on FreeBSD 8 and 9 after extraction
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
