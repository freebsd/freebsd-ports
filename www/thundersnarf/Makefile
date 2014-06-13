# $FreeBSD$

PORTNAME=	thundersnarf
PORTVERSION=	1.3
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.tracanelli.com.br/l/dev/thunder/ \
		${MASTER_SITE_LOCAL}/jmelo

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Web reporting and trending analysis for Thunder Cache Pro

OPTIONS_DEFINE=	APACHE PHP PGSQL DOCS
OPTIONS_DEFAULT=APACHE PHP PGSQL
APACHE_DESC=	Install apache for reporting viewing
PHP_DESC=	Install PHP for reporting generating
PGSQL_DESC=	Install PostgreSQL (report data storing)

USES=		tar:bzip2

NO_BUILD=	yes
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
USE_PHP+=	curl pcre bcmath pdo mcrypt mhash session pgsql spl dom xmlrpc ctype openssl simplexml soap json
.  if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql pgsql
.  endif
.endif

LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl

SUB_FILES=	pkg-message

post-extract:
	# Present on FreeBSD 8 and 9 after extraction
	@${RM} -f ${WRKSRC}/protected/data/bin/._thundersnarf

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/protected/data/bin/thundersnarf* \
		${STAGEDIR}${PREFIX}/bin/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README.pt_BR
.endif

.include <bsd.port.mk>
