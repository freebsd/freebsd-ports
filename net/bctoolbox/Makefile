PORTNAME=	bctoolbox
PORTVERSION=	5.1.38
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://gitlab.linphone.org/BC/public/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications utility library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	mbedtls>=2.3.0_2:security/mbedtls
LIB_DEPENDS=	libbcunit.so:devel/bcunit \
	libmbedtls.so:security/mbedtls

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON

CFLAGS+=	-DHAVE_ARC4RANDOM

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
