PORTNAME=	trean
PORTVERSION=	1.1.10
CATEGORIES=	www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Bookmark Manager
WWW=		https://www.horde.org/apps/trean/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=80 81 82

USES=		horde cpe php
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		content \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Controller \
		Horde_Core \
		Horde_Date \
		Horde_Db \
		Horde_Exception \
		Horde_Form \
		Horde_Queue \
		Horde_Notification \
		Horde_Perms \
		Horde_Util \
		Horde_Vfs \
		Horde_View
USE_PHP=	gettext json

.include <bsd.port.mk>
