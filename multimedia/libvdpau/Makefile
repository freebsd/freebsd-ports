# $FreeBSD$

PORTNAME=	libvdpau
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VDPAU wrapper and tracing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase meson pkgconfig xorg
USE_GITLAB=	yes
USE_XORG=	x11 xext xorgproto
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	vdpau
GL_COMMIT=	f57a9904c43ef5d726320c77baa91d0c38361ed4
MESON_ARGS=	-Ddocumentation=false

post-patch:	.SILENT
	cd ${WRKSRC}/src && ${MV} vdpau_wrapper.cfg vdpau_wrapper.cfg.sample
	${REINPLACE_CMD} 's/vdpau_wrapper.cfg/&.sample/' \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
