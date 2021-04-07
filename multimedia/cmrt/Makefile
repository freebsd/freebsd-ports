PORTNAME=	cmrt
DISTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Legacy C for Metal Runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

LIB_DEPENDS=	libdrm_intel.so:graphics/libdrm \
		libva.so:multimedia/libva

USES=		autoreconf compiler:c11 libtool pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e '/-g/d; /-O2/d' \
		${WRKSRC}/src/Makefile.am
# Silence -Wmacro-redefined
	@${REINPLACE_CMD} -e '/__fastcall/d' \
		${WRKSRC}/src/cm_mem.h
	@${REINPLACE_CMD} -e '/#define UINT_MAX/d' \
		${WRKSRC}/src/oscl_platform_def.h

.include <bsd.port.mk>
