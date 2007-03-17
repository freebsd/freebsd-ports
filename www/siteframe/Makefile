# New ports collection makefile for:	siteframe
# Date created:				9 January 2006
# Whom:					Glen Campbell
#
# $FreeBSD$
#

PORTNAME=	siteframe
PORTVERSION=	5.0.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.broadpool.net/pub/siteframe/

MAINTAINER=	glen@broadpool.com
COMMENT=	A web community content management system in PHP5 and MySQL

RUN_DEPENDS=	${LOCALBASE}/share/smarty/Smarty.class.php:${PORTSDIR}/www/smarty

USE_APACHE=	yes
WITH_APACHE2=	yes
USE_PHP=	mysqli simplexml xml session gd
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4
USE_MYSQL=	yes
DEFAULT_MYSQL_VER=	41
IGNORE_WITH_MYSQL=	40

# where to install
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
WWWDIR?=	${PREFIX}/www
.ifndef SITEFRAMEDIR
.ifdef APACHE_DATADIR
SITEFRAMEDIR=	${APACHE_DATADIR}/siteframe
.else
SITEFRAMEDIR=	${WWWDIR}/siteframe
.endif
.endif

SUB_FILES=	pkg-message
SUB_LIST=	DIR=${SITEFRAMEDIR}

do-install:
	${MKDIR} ${SITEFRAMEDIR}
	${CP} -R ${WRKSRC}/* ${SITEFRAMEDIR}/
	${CHOWN} -R ${WWWOWN} ${SITEFRAMEDIR}/

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
