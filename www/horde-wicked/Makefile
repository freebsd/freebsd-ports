# $FreeBSD$

PORTNAME=	wicked
DISTVERSION=	2.0.2
CATEGORIES=	www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Wiki Application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS+=	${PEARDIR}/Text/Wiki.php:${PORTSDIR}/www/pear-Text_Wiki

USES=	horde
USE_PHP=	gettext
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Core \
		Horde_Db \
		Horde_Exception \
		Horde_Form \
		Horde_Http \
		Horde_Lock \
		Horde_Mail \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Notification \
		Horde_Perms \
		Horde_Rpc \
		Horde_Text_Diff \
		Horde_Url \
		Horde_Util \
		Horde_Vfs

.include <bsd.port.mk>
