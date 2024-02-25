PORTNAME=	libsrtp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	net
PKGNAMESUFFIX=	2

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Secure RTP (SRTP) Reference Implementation
WWW=		https://github.com/cisco/libsrtp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe meson pkgconfig ssl
CPE_VENDOR=	cisco
USE_GITHUB=	yes
GH_ACCOUNT=	cisco
USE_LDCONFIG=	yes

MESON_ARGS=	-Dcrypto-library=openssl \
		-Dcrypto-library-kdf=disabled \
		-Ddoc=disabled

.include <bsd.port.mk>
