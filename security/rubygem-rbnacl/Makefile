# $FreeBSD$

PORTNAME=	rbnacl
PORTVERSION=	4.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Networking and Cryptography (NaCl) library

LICENSE=	MIT

LIB_DEPENDS=	libsodium.so:security/libsodium
BUILD_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler
RUN_DEPENDS=	rubygem-ffi>=0:devel/rubygem-ffi

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
