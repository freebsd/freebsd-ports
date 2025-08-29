PORTNAME=	phpvirtualbox
DISTVERSION=	6.1
PORTREVISION=	6
CATEGORIES=	www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox
WWW=		https://sourceforge.net/projects/phpvirtualbox/

LICENSE=	GPLv3

USES=		dos2unix php:flavors
DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
USE_GITHUB=	yes
GH_TAGNAME=	cf82d58f2
USE_PHP=	session simplexml soap xml

ETCDIR=		${WWWDIR}
EXTRA_PATCHES+=	${.CURDIR}/../phpvirtualbox-72/files/patch-panes_mediumEncryptionPasswords.html \
		${.CURDIR}/../phpvirtualbox-legacy/files/patch-php8
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^6\.

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/share/phpvirtualbox#${WWWDIR}#g' \
		${WRKSRC}/phpvirtualbox.conf
	@${REINPLACE_CMD} -e 's#\r#\n#g' ${WRKSRC}/languages/zh_tw.xml

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
