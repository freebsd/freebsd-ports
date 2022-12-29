PORTNAME=	trean
PORTVERSION=	1.1.10
CATEGORIES=	www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Bookmark Manager
WWW=		https://www.horde.org/apps/trean/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Requires php74
EXPIRATION_DATE=	2023-03-31
BROKEN=	runtime error with php80

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
IGNORE_WITH_PHP=81 82

.include <bsd.port.mk>
