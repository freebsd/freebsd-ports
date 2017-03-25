# $FreeBSD$

PORTNAME=	kickpass
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	bapt@FreeBSD.irg
COMMENT=	Stupid simple password safe

LICENSE=	MIT

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cmake
USE_XORG=	x11

BROKEN_FreeBSD_10=	requires reallocarray(3)

PLIST_FILES=	bin/kickpass \
		lib/libkickpass.so \
		lib/libkickpass.so.0 \
		lib/libkickpass.so.0.1.1 \
		share/man/man1/kickpass.1 \
		share/zsh/site-functions/_kickpass

USE_GITHUB=	yes
GH_ACCOUNT=	paulfariello
USE_LDCONFIG=	yes

.include <bsd.port.mk>
