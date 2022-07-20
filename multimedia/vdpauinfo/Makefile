PORTNAME=	vdpauinfo
PORTVERSION=	1.5
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Tool to query VDPAU capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau

USES=		autoreconf pkgconfig xorg
USE_XORG=	x11
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	vdpau
GL_COMMIT=	d3c5bd63bf8878d59b22d618d2bb5116db392d28
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/vdpauinfo

.include <bsd.port.mk>
