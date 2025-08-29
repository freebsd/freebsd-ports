PORTNAME=	phpvirtualbox
DISTVERSION=	5.2-1
PORTREVISION=	7
CATEGORIES=	www
SUFFIX=		-legacy
PKGNAMESUFFIX=	${SUFFIX}${PHP_PKGNAMESUFFIX}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox
WWW=		https://sourceforge.net/projects/phpvirtualbox/

LICENSE=	GPLv3

USES=		dos2unix php:flavors
DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
USE_GITHUB=	yes
USE_PHP=	session simplexml soap xml

ETCDIR=		${WWWDIR}
WWWDIR=		${PREFIX}/www/${PORTNAME}${SUFFIX}
EXTRA_PATCHES+=	${.CURDIR}/../phpvirtualbox/files/patch-php8 \
		${.CURDIR}/../phpvirtualbox/files/patch-panes_mediumEncryptionPasswords.html
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^5\.

post-patch:
	@${MV} ${WRKSRC}/phpvirtualbox.conf ${WRKSRC}/phpvirtualbox-legacy.conf
	@${REINPLACE_CMD} -e 's#Alias /phpvirtualbox#Alias /phpvirtualbox-legacy#' \
		-e 's#/usr/share/phpvirtualbox#${WWWDIR}#g' \
		${WRKSRC}/phpvirtualbox-legacy.conf
	@${REINPLACE_CMD} -e 's#\r#\n#g' ${WRKSRC}/languages/zh_tw.xml

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
