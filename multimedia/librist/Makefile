PORTNAME=	librist
DISTVERSION=	0.2.15
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Reliable Internet Stream Transport (RIST) protocol
WWW=		https://code.videolan.org/rist/librist

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libmbedcrypto.so:security/mbedtls3 \
		libmicrohttpd.so:www/libmicrohttpd
TEST_DEPENDS=	cmocka>0:sysutils/cmocka

USES=		localbase:ldflags meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	rist
GL_TAGNAME=	561c2536e6c8cc853a2cc7ac757589f312e5e258

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

.include <bsd.port.mk>
