# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Service_Facebook
PORTVERSION=	2.0.6
CATEGORIES=	www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Facebook client

USE_PHP=	json simplexml
USE_HORDE_RUN=	Horde_Exception \
		Horde_Http \
		Horde_Translation \
		Horde_Support

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
