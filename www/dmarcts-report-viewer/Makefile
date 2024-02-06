PORTNAME=	dmarcts-report-viewer
PORTVERSION=	2.0.0.20230615.${GH_TAGNAME}
CATEGORIES=	www mail
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	PHP viewer for DMARC records
WWW=		https://www.techsneeze.com/dmarc-report/

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/highlight.js/LICENSE

USES=		php
USE_PHP=	dom pdo xml
USE_GITHUB=	yes
GH_ACCOUNT=	techsneeze
GH_TAGNAME=	4730985

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	PORTNAME=${PORTNAME}
ETCDIR=		${PREFIX}/etc

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL PGSQL
MYSQL_USE=		PHP=pdo_mysql
PGSQL_USE=		PHP=pdo_pgsql

post-patch:
	cd ${PATCH_WRKSRC} && ${REINPLACE_CMD} \
	    -e 's|%%ETCDIR%%|${ETCDIR}|' \
	    -e 's|%%PORTNAME%%|${PORTNAME}|' \
	    dmarcts-report-viewer-common.php \
	    dmarcts-report-viewer-options.php \
	    dmarcts-report-viewer-report-data.php \
	    dmarcts-report-viewer-report-list.php \
	    dmarcts-report-viewer.php

pre-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/highlight.js/styles

do-install:
	${INSTALL_DATA} /dev/null ${STAGEDIR}${WWWDIR}/index.html
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
	    "-name *\.js -o -name *\.css -o -name *\.png -o -name *\.php"
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-config.php.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
