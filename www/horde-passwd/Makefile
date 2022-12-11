PORTNAME=	passwd
PORTVERSION=	5.0.7
CATEGORIES=	www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde password changing application
WWW=		https://www.horde.org/apps/passwd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_WITH_PHP=80 81 82

USES=		horde cpe php
USE_PHP=	gettext
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Core \
		Horde_Exception \
		Horde_Injector \
		Horde_Util \
		Horde_View

.include <bsd.port.mk>
