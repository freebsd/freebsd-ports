PORTNAME=	phpvirtualbox
DISTVERSION=	7.1-1
PORTREVISION=	1
CATEGORIES=	www
SUFFIX=		-71
PKGNAMESUFFIX=	${SUFFIX}${PHP_PKGNAMESUFFIX}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox
WWW=		https://github.com/phpvirtualbox/phpvirtualbox/

LICENSE=	GPLv3

USES=		php:flavors
USE_GITHUB=	yes
USE_PHP=	session simplexml soap xml

ETCDIR=		${WWWDIR}
WWWDIR=		${PREFIX}/www/${PORTNAME}${SUFFIX}
EXTRA_PATCHES+=	${.CURDIR}/../phpvirtualbox-72/files/patch-endpoints_lib_config.php \
		${.CURDIR}/../phpvirtualbox-72/files/patch-endpoints_lib_vboxconnector.php \
		${.CURDIR}/../phpvirtualbox-72/files/patch-panes_mediumEncryptionPasswords.html
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^7\.1\.

post-patch:
	@${MV} ${WRKSRC}/phpvirtualbox.conf ${WRKSRC}/phpvirtualbox${SUFFIX}.conf
	@${REINPLACE_CMD} -e 's#Alias /phpvirtualbox#Alias /phpvirtualbox${SUFFIX}#' \
		-e 's#/usr/share/phpvirtualbox#${WWWDIR}#g' \
		${WRKSRC}/phpvirtualbox${SUFFIX}.conf
	@${REINPLACE_CMD} -e 's#\r#\n#g' ${WRKSRC}/languages/zh_tw.xml

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
