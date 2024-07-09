PORTNAME=	librist
DISTVERSION=	0.2.10
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Reliable Internet Stream Transport (RIST) protocol
WWW=		https://code.videolan.org/rist/librist

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_15=	compilation fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=280210

LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libmbedcrypto.so:security/mbedtls \
		libmicrohttpd.so:www/libmicrohttpd

USES=		localbase:ldflags meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	rist
GL_TAGNAME=	1e805500dc14a507598cebdd49557c32e514899f

MESON_ARGS=	-Dtest=false

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} --reconfigure ${CONFIGURE_ARGS} -Dtest=true && \
		cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} test

.include <bsd.port.mk>
