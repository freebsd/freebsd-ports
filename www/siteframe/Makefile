# Created by: Glen Campbell
# $FreeBSD$

PORTNAME=	siteframe
PORTVERSION=	5.0.2
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.broadpool.net/pub/siteframe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web community content management system in PHP5 and MySQL

RUN_DEPENDS=	${LOCALBASE}/share/smarty/Smarty.class.php:${PORTSDIR}/www/smarty2

USE_APACHE_RUN=	22+
USE_PHP=	mysqli simplexml xml session gd
DEFAULT_VERS=	php=5
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
PLIST_SUB=	WWWOWN="${WWWOWN}"

do-extract:
	@${MKDIR} ${WRKDIR}/${PORTNAME}
	@ cd ${WRKDIR}/${PORTNAME}; ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTFILES} ${EXTRACT_AFTER_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${SITEFRAMEDIR}/
	${CP} -R ${WRKDIR}/${PORTNAME}/* ${STAGEDIR}${SITEFRAMEDIR}/

.include <bsd.port.mk>
