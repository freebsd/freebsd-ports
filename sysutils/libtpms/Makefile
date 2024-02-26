PORTNAME=	libtpms
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	This library provides emulation of a Trusted Platform Module
WWW=		https://github.com/stefanberger/libtpms

LICENSE=	LIBTPMS
LICENSE_NAME=	LibTPMS
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf gmake libtool pathfix pkgconfig ssl
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	stefanberger
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
