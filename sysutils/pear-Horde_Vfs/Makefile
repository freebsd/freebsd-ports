# Ports collection makefile for:  pear-Horde_Vfs
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Vfs
PORTVERSION=	1.0.6
CATEGORIES=	sysutils www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Virtual File System API

OPTIONS=	FTP "Depend on FTP PHP extension" Off

USE_HORDE_RUN=	Horde_Exception Horde_Translation Horde_Util

.include <bsd.port.pre.mk>

.if defined(WITH_FTP)
USE_PHP+=	ftp
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
