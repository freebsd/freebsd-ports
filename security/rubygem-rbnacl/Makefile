# $FreeBSD$

PORTNAME=	rbnacl
PORTVERSION=	5.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Networking and Cryptography (NaCl) library

LICENSE=	MIT

LIB_DEPENDS=	libsodium.so:security/libsodium
RUN_DEPENDS=	rubygem-ffi>=0:devel/rubygem-ffi

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
