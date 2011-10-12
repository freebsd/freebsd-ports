# Ports collection makefile for:  pear-Horde_Log
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Log
PORTVERSION=	1.1.2
CATEGORIES=	sysutils www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Logging library

OPTIONS=	SCRIBE "Enable scribe support" Off

USE_HORDE_RUN=	Horde_Constraint Horde_Exception

.include <bsd.port.pre.mk>

.if defined(WITH_SCRIBE)
USE_HORDE+=	Horde_Scribe
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
