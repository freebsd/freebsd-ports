# Created by: Glen Campbell
# $FreeBSD$

PORTNAME=	siteframe
PORTVERSION=	5.0.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.broadpool.net/pub/siteframe/

MAINTAINER=	glen@broadpool.com
COMMENT=	A web community content management system in PHP5 and MySQL

RUN_DEPENDS=	${LOCALBASE}/share/smarty/Smarty.class.php:${PORTSDIR}/www/smarty2

USE_APACHE_RUN=	22+
USE_PHP=	mysqli simplexml xml session gd
DEFAULT_PHP_VER=	5
USE_MYSQL=	yes

# where to install
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
.ifndef SITEFRAMEDIR
.ifdef APACHE_DATADIR
SITEFRAMEDIR=	${APACHE_DATADIR}/siteframe
.else
SITEFRAMEDIR=	${WWWDIR}
.endif
.endif

SUB_FILES=	pkg-message
SUB_LIST=	DIR=${SITEFRAMEDIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${SITEFRAMEDIR}/
	${CP} -R ${WRKSRC}/* ${SITEFRAMEDIR}/
	${CHOWN} -R ${WWWOWN} ${SITEFRAMEDIR}/

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
