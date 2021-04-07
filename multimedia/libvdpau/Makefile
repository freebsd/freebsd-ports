PORTNAME=	libvdpau
PORTVERSION=	1.4
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
GL_COMMIT=	c3d1a9dbafdfe6144ff474d0d523dc01b068750f
MESON_ARGS=	-Ddocumentation=false

post-patch:	.SILENT
	cd ${WRKSRC}/src && ${MV} vdpau_wrapper.cfg vdpau_wrapper.cfg.sample
	${REINPLACE_CMD} 's/vdpau_wrapper.cfg/&.sample/' \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
