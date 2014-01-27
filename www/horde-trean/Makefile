# $FreeBSD$

PORTNAME=	trean
PORTVERSION=	1.0.3
CATEGORIES=	www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Bookmark Manager

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LATEST_LINK=	horde-${PORTNAME}

USE_PHP=	gettext json
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

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
