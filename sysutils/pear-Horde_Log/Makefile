# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Log
PORTVERSION=	2.1.0
CATEGORIES=	sysutils www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Logging library

OPTIONS_DEFINE=	SCRIBE
SCRIBE_DESC=	Enable scribe support

USE_HORDE_RUN=	Horde_Constraint \
		Horde_Exception

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSCRIBE}
USE_HORDE+=	Horde_Scribe
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
