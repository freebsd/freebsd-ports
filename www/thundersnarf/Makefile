# $FreeBSD$

PORTNAME=	thundersnarf
PORTVERSION=	1.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.tracanelli.com.br/l/dev/thunder/ \
		${MASTER_SITE_LOCAL}/jmelo

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Web reporting and trending analysis for Thunder Cache Pro

OPTIONS_DEFINE=	APACHE PHP PGSQL DOCS
OPTIONS_DEFAULT=	APACHE PHP PGSQL
APACHE_DESC=	Install apache for reporting viewing
PHP_DESC=	Install PHP for reporting generating
PGSQL_DESC=	Install PostgreSQL (report data storing)

USE_BZIP2=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:R}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
WANT_PGSQL_VER=	84+
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
.endif

.if ${PORT_OPTIONS:MPHP} && ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if ${PORT_OPTIONS:MPHP}
USE_PHP+=	curl pcre bcmath pdo mcrypt mhash session pgsql spl dom xmlrpc ctype openssl simplexml soap json
.endif

LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl:install

SUB_FILES=	pkg-message

do-install:
	@${CP} -R ${WRKSRC} ${WWWDIR}
	@${INSTALL_SCRIPT} -m 555 ${WRKSRC}/protected/data/bin/thundersnarf ${PREFIX}/bin/
	@${INSTALL_SCRIPT} -m 555 ${WRKSRC}/protected/data/bin/thundersnarf-poll ${PREFIX}/bin/
	@${CHGRP} -R ${WWWGRP}	${WWWDIR}/protected/runtime \
		${WWWDIR}/assets
	@${CHMOD} -R g+rwx ${WWWDIR}/protected/runtime \
		${WWWDIR}/assets

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rv ${WRKSRC}/README ${DOCSDIR}/README.pt_BR
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
