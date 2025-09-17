PORTNAME=	bctoolbox
DISTVERSION=	5.4.28
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications utility library
WWW=		https://gitlab.linphone.org/BC/public/bctoolbox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

IGNORE_FreeBSD_13=	is not supported on systems with OpenSSL 1.1.1

LIB_DEPENDS=	libbcunit.so:devel/bcunit

USES=		cmake compiler:c++17-lang ssl
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON \
		-DENABLE_MBEDTLS=OFF -DENABLE_OPENSSL=ON
CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		ENABLE_UNIT_TESTS

CFLAGS+=	-DHAVE_ARC4RANDOM
LDFLAGS+=		-lpthread

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
