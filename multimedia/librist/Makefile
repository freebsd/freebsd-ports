PORTNAME=	librist
DISTVERSION=	0.2.0-RC6
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Reliable Internet Stream Transport (RIST) protocol

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcjson.so:devel/libcjson \
		liblz4.so:archivers/liblz4 # binary doesn't depend on liblz4.so for unknown reason, notified the dev via e-mail on 2021-04-08

USES=		localbase meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	rist
GL_COMMIT=	9604b7530606b26a40fd95092a2f59d3ee6907d9

MESON_ARGS=	-Dtest=false
MESON_ARGS+=	-Duse_mbedtls=false # mbedcrypto needs to be ported

do-test:
	@cd ${WRKSRC} && \
		${RM} -r _build && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} -Dtest=true -Duse_mbedtls=false && \
		cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} test

.include <bsd.port.mk>
