PORTNAME=	librist
DISTVERSION=	0.2.17
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Reliable Internet Stream Transport (RIST) protocol
WWW=		https://code.videolan.org/rist/librist

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libmbedcrypto.so:security/mbedtls3 \
		libmicrohttpd.so:www/libmicrohttpd \
		liblz4.so:archivers/liblz4
TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USES=		localbase:ldflags meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	rist
GL_TAGNAME=	e939a9a4e3df41808fa20f1397ae19b2c4876b1f

MESON_ARGS=	-Dtest=false

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS:N-Dtest=*} --reconfigure -Dtest=true && \
		cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

# tests as of 0.2.15:
# Ok:                20
# Expected Fail:     7
# Fail:              0

# tests as of 0.2.17:
# Ok:                44  
# Expected Fail:     11  
# Fail:              1   

.include <bsd.port.mk>
