# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Log
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	sysutils www pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Logging library

OPTIONS_DEFINE=	SCRIBE
SCRIBE_DESC=	Enable scribe support

USES=	horde
USE_HORDE_RUN=	Horde_Constraint \
		Horde_Exception

SCRIBE_USE=	HORDE_RUN=Horde_Scribe

.include <bsd.port.mk>
