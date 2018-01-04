# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Kolab_Storage
DISTVERSION=	2.2.3
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde library for handling Kolab data stored on an IMAP server

USES=	horde
USE_HORDE_RUN=	Horde_Cache \
		Horde_Exception \
		Horde_Kolab_Format \
		Horde_Mime \
		Horde_Translation \
		Horde_Support \
		Horde_Util

# Optional but we want it
USE_PHP+=	imap
USE_HORDE_RUN+=	Horde_Imap_Client

.include <bsd.port.mk>
