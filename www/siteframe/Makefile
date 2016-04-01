# Created by: Glen Campbell
# $FreeBSD$

PORTNAME=	siteframe
PORTVERSION=	5.0.2
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.broadpool.net/pub/siteframe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web community content management system in PHP5 and MySQL

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/share/smarty/Smarty.class.php:www/smarty2

USE_APACHE_RUN=	22+
USE_PHP=	mysqli simplexml xml session gd
DEFAULT_VERS=	php=5
USE_MYSQL=	yes

# where to install
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/__site
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

post-extract:
	@${MKDIR} ${WRKSRC}
	@(cd ${WRKDIR} && ${MV} [CLRa-z]* _htaccess ${WRKSRC})

do-install:
	${MKDIR} ${STAGEDIR}${SITEFRAMEDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${SITEFRAMEDIR})

.include <bsd.port.mk>
