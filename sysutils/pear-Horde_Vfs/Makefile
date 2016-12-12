# $FreeBSD$

PORTNAME=	Horde_Vfs
PORTVERSION=	2.3.4
CATEGORIES=	sysutils www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Virtual File System API

USE_HORDE_RUN=	Horde_Exception \
		Horde_Translation \
		Horde_Util

OPTIONS_DEFINE=	FTP
FTP_DESC=	Depend on FTP PHP extension

USES=	horde

FTP_USE=	PHP=ftp

.include <bsd.port.mk>
