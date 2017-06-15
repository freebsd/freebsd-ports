# $FreeBSD$

PORTNAME=	passwd
PORTVERSION=	5.0.6
CATEGORIES=	www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde password changing application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	horde cpe
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
