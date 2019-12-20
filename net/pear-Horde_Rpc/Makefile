# $FreeBSD$

PORTNAME=	Horde_Rpc
DISTVERSION=	2.1.9
CATEGORIES=	net www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde RPC API

USES=	horde
USE_HORDE_RUN=	Horde_Core \
		Horde_Dav \
		Horde_Exception \
		Horde_Perms \
		Horde_Serialize \
		Horde_Support \
		Horde_Translation \
		Horde_Util \
		Horde_Xml_Element

# Optional but we want it
USE_HORDE_RUN+=	Horde_ActiveSync \
		Horde_Lock \
		Horde_SyncMl \
		Horde_Http

.include <bsd.port.mk>
