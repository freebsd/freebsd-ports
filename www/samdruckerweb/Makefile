PORTNAME=	samdrucker
DISTVERSION=	0.3.2
CATEGORIES=	www
PKGNAMESUFFIX=	web

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Read-only website for browsing SamDrucker package data
WWW=		https://github.com/dlangille/SamDrucker

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php
USE_PHP=	pdo_pgsql

USE_GITHUB=	yes
GH_ACCOUNT=	dlangille
GH_PROJECT=	SamDrucker

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

# Its own directories, not those of samdruckerserver: the check-in
# server's web root is ${PREFIX}/www/samdrucker, and the website must not
# be reachable through it. The configuration stays in etc/samdrucker.
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/include ${STAGEDIR}${WWWDIR}/www
	${INSTALL_DATA} ${WRKSRC}/servers/php/web/include/common.php \
		${STAGEDIR}${WWWDIR}/include
	${INSTALL_DATA} ${WRKSRC}/servers/php/web/www/*.php \
		${WRKSRC}/servers/php/web/www/samdrucker.css \
		${WRKSRC}/servers/php/web/www/samdrucker.js \
		${STAGEDIR}${WWWDIR}/www
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/servers/php/web/samdruckerweb.conf.sample \
		${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/servers/php/web/README.md \
		${WRKSRC}/servers/php/web/nginx-config.conf \
		${WRKSRC}/PostgreSQL/updates-website.sql \
		${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}${PKGNAMESUFFIX}.conf.sample

.include <bsd.port.mk>
