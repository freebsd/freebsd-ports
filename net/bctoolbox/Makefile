PORTNAME=	bctoolbox
DISTVERSION=	5.4.28
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications utility library
WWW=		https://gitlab.linphone.org/BC/public/bctoolbox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

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

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} < 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl111}
IGNORE=	is not supported on systems with OpenSSL 1.1.1
.endif

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
