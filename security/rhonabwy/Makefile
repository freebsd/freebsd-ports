PORTNAME=	rhonabwy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Javascript Object Signing and Encryption (JOSE) library
WWW=		https://github.com/babelouest/rhonabwy

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	yder>1.4.14:devel/yder \
		orcania>2.2.1:devel/orcania \
		gnutls>0:security/gnutls

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgmp.so:math/gmp \
		libnettle.so:security/nettle \
		libjansson.so:devel/jansson \
		libgnutls.so:security/gnutls \
		liborcania.so:devel/orcania \
		libyder.so:devel/yder

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

PLIST_SUB=	DISTVERSION=${DISTVERSION}

CMAKE_ARGS=	-DWITH_JOURNALD=off

.include <bsd.port.mk>
