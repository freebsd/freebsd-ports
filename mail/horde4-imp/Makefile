# Ports collection makefile for:  imp3
# Date created:			  Mon Oct 08, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	imp
PORTVERSION=	5.0.14
CATEGORIES=	mail www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based webmail system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	horde4-${PORTNAME}

USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Browser \
		Horde_Compress \
		Horde_Core \
		Horde_Crypt \
		Horde_Date \
		Horde_Editor \
		Horde_Exception \
		Horde_Form \
		Horde_Icalendar \
		Horde_Image \
		Horde_Imap_Client \
		Horde_Itip \
		Horde_LoginTasks \
		Horde_Mail \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Nls \
		Horde_Notification \
		Horde_Perms \
		Horde_Serialize \
		Horde_SpellChecker \
		Horde_Support \
		Horde_Text_Filter \
		Horde_Text_Flowed \
		Horde_Token \
		Horde_Tree \
		Horde_Url \
		Horde_Util \
		Horde_View

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
