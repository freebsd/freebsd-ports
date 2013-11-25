# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Kolab_Session
PORTVERSION=	2.0.1
CATEGORIES=	net www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde library for managing an active Kolab session

USE_HORDE_RUN=	Horde_Exception

# Optional but we want it
USE_HORDE_RUN+=	Horde_Kolab_Server \
		Horde_Log

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
