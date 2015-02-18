# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	phpvirtualbox
DISTVERSION=	4.3-2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME} \
		LOCAL/decke

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	AJAX Web Interface for VirtualBox

LICENSE=	GPLv3

NO_BUILD=	yes
USE_PHP=	json session soap simplexml xml
USES=		dos2unix zip

DOS2UNIX_REGEX=	.*\.(php|txt|js|css|html)
ETCDIR=		${WWWDIR}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} \
	    "-not -name *.orig -not -name config.php-example")
	${INSTALL_DATA} ${WRKSRC}/config.php-example \
	    ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
