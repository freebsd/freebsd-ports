# $FreeBSD$

PORTNAME=	wicked
DISTVERSION=	2.0.1
CATEGORIES=	www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Wiki Application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	horde-${PORTNAME}

RUN_DEPENDS+=	${PEARDIR}/Text/Wiki.php:${PORTSDIR}/www/pear-Text_Wiki

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
