PORTNAME=	librist
DISTVERSION=	0.2.14
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Reliable Internet Stream Transport (RIST) protocol
WWW=		https://code.videolan.org/rist/librist

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libmbedcrypto.so:security/mbedtls3 \
		libmicrohttpd.so:www/libmicrohttpd

USES=		localbase:ldflags meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	rist
GL_TAGNAME=	91a88de284542ec0414e32e5b884ba33b3fd3b91

MESON_ARGS=	-Dtest=false

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} --reconfigure ${CONFIGURE_ARGS} -Dtest=true && \
		cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} test

.include <bsd.port.mk>
