PORTNAME=	librist
DISTVERSION=	0.2.7
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Reliable Internet Stream Transport (RIST) protocol

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libmbedcrypto.so:security/mbedtls

USES=		localbase:ldflags meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	rist
GL_COMMIT=	00d1d3e33fb654d4744ce91fa838b413a4408494

MESON_ARGS=	-Dtest=false

do-test:
	@cd ${WRKSRC} && \
		${RM} -r _build && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} -Dtest=true && \
		cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} test

.include <bsd.port.mk>
