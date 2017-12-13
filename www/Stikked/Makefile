# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Stikked
DISTVERSION=	0.12.0
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	PHP-based Pastebin, with a simple and easy to use user interface

USES=		php:web

USE_GITHUB=	yes
GH_ACCOUNT=	claudehohl

WANT_PGSQL=	client
WANT_SQLITE=	client
WANT_MYSQL=	client

USE_PHP=	gd pdo session ctype filter pgsql
PGSQL_USE=	PHP=pdo_pgsql

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${INSTALL_DATA} ${STAGEDIR}${WWWDIR}/application/config/stikked.php.dist ${STAGEDIR}${ETCDIR}/stikked.php.sample
	${LN} -sf ${ETCDIR}/stikked.php ${STAGEDIR}${WWWDIR}/application/config/

.include <bsd.port.mk>
