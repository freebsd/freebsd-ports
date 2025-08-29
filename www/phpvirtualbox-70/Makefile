PORTNAME=	phpvirtualbox
DISTVERSION=	7.0
CATEGORIES=	www
MASTER_SITES=	https://sourceforge.net/code-snapshots/git/p/ph/${PORTNAME}-7-0/code.git/ \
		LOCAL/vvd
SUFFIX=		-70
PKGNAMESUFFIX=	${SUFFIX}${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}-7-0-code-0737ff1c4106661672e69ef5ff26c3f494f4c65f

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox
WWW=		https://sourceforge.net/projects/phpvirtualbox-7-0/

LICENSE=	GPLv3

USES=		php:flavors zip
USE_PHP=	session simplexml soap xml

ETCDIR=		${WWWDIR}
WWWDIR=		${PREFIX}/www/${PORTNAME}${SUFFIX}
EXTRA_PATCHES+=	${.CURDIR}/../phpvirtualbox-72/files/patch-endpoints_lib_vboxconnector.php \
		${.CURDIR}/../phpvirtualbox-72/files/patch-panes_mediumEncryptionPasswords.html
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^7\.0\.

WRKSRC_SUBDIR=	${PORTNAME}-${DISTVERSION}

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
