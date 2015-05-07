# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	libcapn
DISTVERSION=	1.0.0beta3
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	C Library to interact with Apple Push Notification Service

LICENSE=	MIT

LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	adobkin

USES=		cmake
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DOS_FREEBSD=yes

.include <bsd.port.mk>
