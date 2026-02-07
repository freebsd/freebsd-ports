PORTNAME=	libtpms
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
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
GH_ACCOUNT=	stefanberger
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
