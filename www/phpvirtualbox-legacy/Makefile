PORTNAME=	phpvirtualbox
DISTVERSION=	5.2-1
PORTREVISION=	1
CATEGORIES=	www
PKGNAMESUFFIX=	-legacy

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox

LICENSE=	GPLv3

USES=		dos2unix php
USE_PHP=	json session simplexml soap xml

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes

DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
ETCDIR=		${WWWDIR}

post-patch:
	@${MV} ${WRKSRC}/phpvirtualbox.conf ${WRKSRC}/phpvirtualbox-legacy.conf
	@${REINPLACE_CMD} -e 's#Alias /phpvirtualbox#Alias /phpvirtualbox-legacy#' \
		-e 's#/usr/share/phpvirtualbox#${WWWDIR}#g' \
		${WRKSRC}/phpvirtualbox-legacy.conf

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
