# Created by: Alexander Brovikov <alexander@brovikov.ru>
# $FreeBSD$

PORTNAME=	libsrtp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.4
CATEGORIES=	net

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Secure RTP (SRTP) Reference Implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	cisco

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-openssl
USES=		cpe localbase gmake pathfix pkgconfig ssl
CPE_VENDOR=	cisco
USE_LDCONFIG=	yes

ALL_TARGET=	all shared_library
TEST_TARGET=	runtest
TEST_ENV=	LD_LIBRARY_PATH=${WRKSRC}

.if ! defined(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

post-patch:
	@${REINPLACE_CMD} '/pkg-config.*openssl/d' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
