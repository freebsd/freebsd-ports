# $FreeBSD$

PORTNAME=	klg
PORTVERSION=	1.5
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF \
		ftp://ftpmirror.uk/freebsd-ports/klg/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	PHP-based looking glass for Cisco, Juniper and Quagga/Zebra routers

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build

USES=		tar:txz
USE_MYSQL=	yes
USE_PHP=	mysql pcre sockets xml
WANT_PHP_WEB=	yes
NO_ARCH=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	%%DATADIR%%/CREDITS \
		%%DATADIR%%/ChangeLog \
		%%DATADIR%%/klg_README.txt \
		%%DATADIR%%/klg_schema.sql \
		%%WWWDIR%%/klg.php \
		"@sample %%WWWDIR%%/klg_config.php.sample" \
		"@sample %%WWWDIR%%/klg_template.html.sample" \
		%%WWWDIR%%/klg_router_functions.php
SUB_FILES+=	pkg-message

OPTIONS_DEFINE=		SSH2
OPTIONS_DEFAULT=	SSH2

SSH2_DESC=		SSH2 support for router access

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSH2}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/ssh2.so:security/pecl-ssh2
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/CREDITS ${WRKSRC}/ChangeLog ${WRKSRC}/klg_README.txt \
		${WRKSRC}/klg_schema.sql ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/klg.php ${WRKSRC}/klg_router_functions.php ${STAGEDIR}/${WWWDIR}
	${CP} ${WRKSRC}/klg_config.php ${STAGEDIR}/${WWWDIR}/klg_config.php.sample
	${CP} ${WRKSRC}/klg_template.html ${STAGEDIR}/${WWWDIR}/klg_template.html.sample

.include <bsd.port.mk>
