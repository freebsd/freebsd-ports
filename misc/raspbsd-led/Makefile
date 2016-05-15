# $FreeBSD$

PORTNAME=	raspbsd-led
PORTVERSION=	0.2_1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Misc LED programs for ARM boards

USE_GITHUB=	yes
GH_ACCOUNT=	raspbsd
ONLY_FOR_ARCHS=	armv6
USE_RC_SUBR=	flash-heartbead-led
PLIST_FILES=	sbin/flash-heartbeat-led

.include <bsd.port.mk>
