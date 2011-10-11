# Ports collection makefile for:  horde4-wicked
# Date created:			  Oct 11, 2011
# Whom:				  Martin Matuska (mm@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	wicked
DISTVERSION=	1.0.0RC1
CATEGORIES=	www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Wiki Application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	horde4-${PORTNAME}

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

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
