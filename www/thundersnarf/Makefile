# New ports collection makefile for:	thundersnarf
# Date created:		2010-05-20
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	thundersnarf
PORTVERSION=	1.02b
CATEGORIES=	www
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/thunder/ \
		${MASTER_SITE_LOCAL}/jmelo

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Web reporting and trending analysis for Thunder Cache Pro

OPTIONS=	APACHE "Install apache for reporting viewing" on \
		PHP "Install PHP for reporting generating" on \
		PGSQL "Install PostgreSQL (report data storing)" on

USE_BZIP2=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:R}

MANUAL_PACKAGE_BUILD=	This port wants PGSQL 8.4, but 8.2 is default and used to build php5-pgsql dependency.

.include <bsd.port.pre.mk>

.if defined (WITH_APACHE)
USE_APACHE=	2.0+
.endif

.if defined (WITH_PGSQL)
USE_PGSQL=	yes
WANT_PGSQL_VER=	84
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
.endif

.if defined(WITH_PHP) && defined(WITH_PGSQL)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if defined(WITH_PHP)
USE_PHP+=	curl pcre bcmath pdo mcrypt mhash session pgsql spl dom xmlrpc ctype
.endif

LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl:install

SUB_FILES=	pkg-message

do-install:
	@${CP} -R ${WRKSRC} ${WWWDIR}
	@${INSTALL_SCRIPT} -m 555 ${WRKSRC}/protected/data/bin/thundersnarf ${PREFIX}/bin/
	@${INSTALL_SCRIPT} -m 555 ${WRKSRC}/protected/data/bin/thundersnarf-poll ${PREFIX}/bin/
	@${CHGRP} -R ${WWWGRP}	${WWWDIR}/protected/runtime \
		${WWWDIR}/assets
	@${CHMOD} -R g+rwx ${WWWDIR}/protected/runtime \
		${WWWDIR}/assets

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rv ${WRKSRC}/README ${DOCSDIR}/README.pt_BR
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
