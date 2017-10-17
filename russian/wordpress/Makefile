# Created by: Mihail Timofeev <9267096@gmail.com>
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	4.8.2
DISTVERSIONSUFFIX=	-ru_RU
CATEGORIES=	russian www
MASTER_SITES=	http://ru.wordpress.org/

MAINTAINER=	9267096@gmail.com
COMMENT=	State-of-the-art semantic personal publishing platform

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

CONFLICTS_INSTALL=	wordpress-[0-9].* de-wordpress-[0-9].* ja-wordpress-[0-9].*

NO_ARCH=	yes
NO_BUILD=	yes
USES=		php:web cpe
USE_PHP=	curl gd hash mysqli pcre tokenizer xml zip zlib ftp
WRKSRC=		${WRKDIR}/${PORTNAME}

CPE_LANG=	ru
.if ${PORTVERSION:N*.*.*}
CPE_VERSION=	${PORTVERSION}.0
.endif

SUB_FILES=	pkg-message
PLIST=		${WRKDIR}/pkg-plist
PORTDOCS=	license.txt readme.html

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	${ECHO_CMD} '@owner www' > ${PLIST}
	${ECHO_CMD} '@group www' >> ${PLIST}
	cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SED} -e 's|^|%%WWWDIR%%/|' >> ${PLIST}
	${ECHO_CMD} '@owner' >> ${PLIST}
	${ECHO_CMD} '@group' >> ${PLIST}
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/
	${FIND} ${STAGEDIR}${WWWDIR}/ -type d -exec ${CHMOD} g+w {} \;

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
