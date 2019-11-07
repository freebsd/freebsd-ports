# $FreeBSD$

PORTNAME=	kickpass
PORTVERSION=	0.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Stupid simple password safe

LICENSE=	MIT

LIB_DEPENDS=	libsodium.so:security/libsodium \
		libevent.so:devel/libevent
BUILD_DEPENDS=	checkmk:devel/check

USES=		cmake xorg
USE_XORG=	x11

PLIST_FILES=	bin/kickpass \
		lib/libkickpass.so \
		lib/libkickpass.so.0 \
		lib/libkickpass.so.0.2.0 \
		man/man1/kickpass.1.gz \
		share/zsh/site-functions/_kickpass

USE_GITHUB=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
