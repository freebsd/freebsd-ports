PORTNAME=	neatvnc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.5
CATEGORIES=	net

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Liberally licensed VNC server library
WWW=		https://github.com/any1/neatvnc

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm
LIB_DEPENDS=	libaml.so:devel/aml

USES=		compiler:c11 meson pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
USE_LDCONFIG=	yes
GH_ACCOUNT=	any1

OPTIONS_DEFINE=	FFMPEG GNUTLS JPEG NETTLE OPENGL
OPTIONS_DEFAULT=FFMPEG GNUTLS JPEG NETTLE OPENGL

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_MESON_ENABLED=	h264

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MESON_ENABLED=	tls

JPEG_LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo
JPEG_MESON_ENABLED=	jpeg

NETTLE_DESC=		Low-level encryption via Nettle
NETTLE_LIB_DEPENDS=	libgmp.so:math/gmp \
			libnettle.so:security/nettle
NETTLE_MESON_ENABLED=	nettle

OPENGL_LIB_DEPENDS=	libdrm.so:graphics/libdrm
OPENGL_USES=		gl
OPENGL_USE=		GL=gbm
OPENGL_MESON_ENABLED=	gbm

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=true"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
