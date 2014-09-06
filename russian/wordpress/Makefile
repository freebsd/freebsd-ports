# Created by: Mihail Timofeev <9267096@gmail.com>
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	4.0
CATEGORIES=	russian www
MASTER_SITES=	http://ru.wordpress.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-ru_RU

MAINTAINER=	9267096@gmail.com
COMMENT=	State-of-the-art semantic personal publishing platform

LICENSE=	GPLv2

CONFLICTS_INSTALL=	wordpress-3.* de-wordpress-3.* ja-wordpress-3.*

NO_BUILD=	yes
USE_PHP=	curl gd mysql pcre tokenizer xml zip
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

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
	cd ${WRKSRC}/ && ${FIND} -d . -type d | ${SED} -e 's|^\.|@dirrm %%WWWDIR%%|' >> ${PLIST}
	${ECHO_CMD} '@owner' >> ${PLIST}
	${ECHO_CMD} '@group' >> ${PLIST}
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/
	${FIND} ${STAGEDIR}${WWWDIR}/ -type d -exec ${CHMOD} g+w '{}' \;
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
