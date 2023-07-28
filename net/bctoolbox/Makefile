PORTNAME=	bctoolbox
DISTVERSION=	5.2.94
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications utility library
WWW=		https://gitlab.linphone.org/BC/public/bctoolbox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	mbedtls>=2.3.0_2:security/mbedtls
LIB_DEPENDS=	libbcunit.so:devel/bcunit \
	libmbedtls.so:security/mbedtls

USES=		cmake compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO -DENABLE_STRICT=NO \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON

CFLAGS+=	-DHAVE_ARC4RANDOM

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
