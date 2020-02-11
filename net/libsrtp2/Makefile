# $FreeBSD$

PORTNAME=	libsrtp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	net
PKGNAMESUFFIX=	2

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Secure RTP (SRTP) Reference Implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	cisco

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-openssl \
		crypto_CFLAGS="-I${OPENSSLINC}" \
		crypto_LIBS="${OPENSSLLIB}/libcrypto.so"
USES=		cpe gmake pkgconfig ssl
CPE_VENDOR=	cisco
USE_LDCONFIG=	yes

ALL_TARGET=	all shared_library
TEST_TARGET=	runtest
TEST_ENV=	LD_LIBRARY_PATH=${WRKSRC}

post-patch:
	@${REINPLACE_CMD} '/supported_cflags=.*-fPIC/d' ${WRKSRC}/configure

.include <bsd.port.mk>
