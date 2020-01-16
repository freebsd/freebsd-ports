# $FreeBSD$

PORTNAME=	helib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of homomorphic encryption

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libntl.so:math/ntl

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	homenc
GH_PROJECT=	HElib
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED

.include <bsd.port.mk>
