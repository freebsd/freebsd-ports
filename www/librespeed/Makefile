# $FreeBSD$

PORTNAME=	librespeed
DISTVERSION=	5.2
CATEGORIES=	www net
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	Lightweight selfhosted speedtest

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	php:flavors,web

USE_GITHUB=	YES
GH_PROJECT=	speedtest

NO_BUILD=	YES
NO_ARCH=	YES

PLIST_SUB=	LIBRESPEED_USERNAME=${WWWOWN}

OPTIONS_DEFINE=	DOCS EXAMPLES

OPTIONS_RADIO=	BACKEND
OPTIONS_RADIO_BACKEND=	MYSQL PGSQL SQLITE

MYSQL_USE=	PHP=mysqli
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKSRC}/*.js ${WRKSRC}/favicon.ico ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/backend
	cd ${WRKSRC}/backend && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/backend
	@${MKDIR} ${STAGEDIR}${WWWDIR}/results
	cd ${WRKSRC}/results && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/results
	${INSTALL_DATA} ${WRKSRC}/results/telemetry_settings.php \
		${STAGEDIR}${WWWDIR}/results/telemetry_settings.php.sample
	${INSTALL_DATA} ${WRKSRC}/backend/getIP_ipInfo_apikey.php \
		${STAGEDIR}${WWWDIR}/backend/getIP_ipInfo_apikey.php.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -a ${WRKSRC}/*.html ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
