# ex:ts=8
# Ports collection makefile for:	libmsn
# Date created:			Feb 6, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libmsn
DISTVERSION=	4.1
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	decept0@gmail.com
COMMENT=	A library for connecting to MSN Messenger service

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|crypto|${OPENSSLLIB}/libcrypto.so|g' -e 's|ssl|${OPENSSLLIB}/libssl.so|g' \
		${WRKSRC}/msn/CMakeLists.txt \
		${WRKSRC}/msntest/CMakeLists.txt

.include <bsd.port.mk>
