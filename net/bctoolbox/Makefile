PORTNAME=	bctoolbox
PORTVERSION=	5.1.38
CATEGORIES=	net
MASTER_SITES=	https://gitlab.linphone.org/BC/public/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications utility library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	mbedtls>=2.3.0_2:security/mbedtls
LIB_DEPENDS=	libmbedtls.so:security/mbedtls

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO \
		-DENABLE_TESTS_COMPONENT=NO \
		-DCMAKE_SKIP_INSTALL_RPATH=ON

CFLAGS+=	-DHAVE_ARC4RANDOM

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
