# $FreeBSD$

PORTNAME=	klg
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF \
		ftp://ftpmirror.uk/freebsd-ports/klg/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	PHP-based looking glass for Cisco, Juniper and Quagga/Zebra routers

LICENSE=	BSD3CLAUSE

USES=		tar:txz php:web,flavors mysql:client
USE_PHP=	mysqli pcre sockets xml

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/CREDITS \
		${DATADIR}/ChangeLog \
		${DATADIR}/klg_README.txt \
		${DATADIR}/klg_schema.sql \
		${WWWDIR}/klg.php \
		"@sample ${WWWDIR}/klg_config.php.sample" \
		"@sample ${WWWDIR}/klg_template.html.sample" \
		${WWWDIR}/klg_router_functions.php
SUB_FILES+=	pkg-message

OPTIONS_DEFINE=		SSH2
OPTIONS_DEFAULT=	SSH2

SSH2_DESC=		SSH2 support for router access

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSSH2}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/ssh2.so:security/pecl-ssh2@${PHP_FLAVOR}
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/CREDITS ${WRKSRC}/ChangeLog ${WRKSRC}/klg_README.txt \
		${WRKSRC}/klg_schema.sql ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/klg.php ${WRKSRC}/klg_router_functions.php ${STAGEDIR}/${WWWDIR}
	${CP} ${WRKSRC}/klg_config.php ${STAGEDIR}/${WWWDIR}/klg_config.php.sample
	${CP} ${WRKSRC}/klg_template.html ${STAGEDIR}/${WWWDIR}/klg_template.html.sample

.include <bsd.port.post.mk>
