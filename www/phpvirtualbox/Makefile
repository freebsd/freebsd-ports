# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	phpvirtualbox
DISTVERSION=	5.1-1
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox

LICENSE=	GPLv3

NO_ARCH=	yes
NO_BUILD=	yes
USES=		dos2unix php
USE_PHP=	json session simplexml soap xml

USE_GITHUB=	yes
GH_TAGNAME=	65ebced

DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
ETCDIR=		${WWWDIR}

post-patch:
	@${MV} ${WRKSRC}/endpoints/lib/vboxweb-5.0.wsdl ${WRKSRC}/endpoints/lib/vboxweb-5.1.wsdl
	@${MV} ${WRKSRC}/endpoints/lib/vboxwebService-5.0.wsdl ${WRKSRC}/endpoints/lib/vboxwebService-5.1.wsdl

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
