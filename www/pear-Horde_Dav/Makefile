# $FreeBSD$

PORTNAME=	Horde_Dav
PORTVERSION=	1.0.3
CATEGORIES=	www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde library for WebDAV, CalDAV, CardDAV

LICENSE=	BSD

USE_HORDE_RUN=	Horde_Auth \
		Horde_Core \
		Horde_Stream

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
