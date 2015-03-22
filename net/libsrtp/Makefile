# Created by: Alexander Brovikov <alexander@brovikov.ru>
# $FreeBSD$

PORTNAME=	libsrtp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	alexander@brovikov.ru
COMMENT=	Secure RTP (SRTP) Reference Implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	cisco

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-openssl
CFLAGS+=	-fPIC	# Taken from configure script
USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

.if ! defined(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's/@LDFLAGS@ -L\./-L. @LDFLAGS@/' \
		-e 's/libsrtp.so/&.0/g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/pkg-config/s/openssl/libcrypto/' \
		${WRKSRC}/configure

post-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} libsrtp.so.0)

post-install:
	${LN} -s libsrtp.so.0 ${STAGEDIR}${PREFIX}/lib/libsrtp.so

.include <bsd.port.mk>
