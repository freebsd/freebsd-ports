# $FreeBSD$

PORTNAME=	neatvnc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	net

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Liberally licensed VNC server library

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm
LIB_DEPENDS=	libaml.so:devel/aml

USES=		compiler:c11 meson pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
USE_LDCONFIG=	yes
GH_ACCOUNT=	any1

OPTIONS_DEFINE=	GNUTLS JPEG
OPTIONS_DEFAULT=GNUTLS JPEG

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MESON_ENABLED=	tls

JPEG_LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo
JPEG_MESON_ENABLED=	jpeg

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
