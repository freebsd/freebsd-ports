# Created by: ijliao
# $FreeBSD$

PORTNAME=	libmsn
DISTVERSION=	4.2.1
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A library for connecting to MSN Messenger service

LICENSE=	GPLv2

DEPRECATED=	Primary MSN Messenger service terminated 30 APR 2013
EXPIRATION_DATE=2013-10-31

USE_BZIP2=	yes
USES=		cmake
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|crypto|${OPENSSLLIB}/libcrypto.so|g' -e 's|ssl|${OPENSSLLIB}/libssl.so|g' \
		${WRKSRC}/msn/CMakeLists.txt \
		${WRKSRC}/msntest/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|SOVERSION 0.3|SOVERSION 0|g' \
		${WRKSRC}/msn/CMakeLists.txt

.include <bsd.port.mk>
