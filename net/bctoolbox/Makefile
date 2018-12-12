# $FreeBSD$

PORTNAME=	bctoolbox
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.linphone.org/releases/sources/bctoolbox/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Belledonne Communications utility library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mbedtls>=2.3.0_2:security/mbedtls
LIB_DEPENDS=	libmbedtls.so:security/mbedtls

USES=		cmake:outsource compiler:c++11-lib
USE_LDCONFIG=	yes

CFLAGS+=	-DHAVE_ARC4RANDOM
CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO \
		-DENABLE_TESTS_COMPONENT=NO

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
