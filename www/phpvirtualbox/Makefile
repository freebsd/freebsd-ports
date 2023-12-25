PORTNAME=	phpvirtualbox
DISTVERSION=	6.1
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox
WWW=		https://sourceforge.net/projects/phpvirtualbox/

LICENSE=	GPLv3

USES=		dos2unix php
USE_PHP=	session simplexml soap xml

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_TAGNAME=	cf82d58f2

DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
ETCDIR=		${WWWDIR}

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/share/phpvirtualbox#${WWWDIR}#g' \
		${WRKSRC}/phpvirtualbox.conf

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
