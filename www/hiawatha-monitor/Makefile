PORTNAME=	hiawatha-monitor
DISTVERSION=	1.7
CATEGORIES=	www
MASTER_SITES=	https://hiawatha.leisink.net/files/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	monitor-${DISTVERSION}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Monitoring tool for the Hiawatha web server
WWW=		https://hiawatha.leisink.net/monitor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:flavors shebangfix
USE_PHP=	ctype mysqli xml xsl zlib
SHEBANG_FILES=	database/delete_old_logs \
		database/fetch_webserver_logs \
		database/flush_cache \
		database/private_pages \
		database/send_reports \
		database/set_password

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/var/www/monitor,${WWWDIR},g' ${WRKSRC}/INSTALL

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	cd ${STAGEDIR}${WWWDIR} && ${CHMOD} ${BINMODE} ${SHEBANG_FILES}
.for f in banshee.conf private_pages.conf public_pages.conf
	${MV} ${STAGEDIR}${WWWDIR}/settings/${f} \
		${STAGEDIR}${WWWDIR}/settings/${f}.sample
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
