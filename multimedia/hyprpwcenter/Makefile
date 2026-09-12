PORTNAME=	hyprpwcenter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	4
CATEGORIES=	multimedia

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GUI Pipewire control center
WWW=		https://github.com/hyprwm/hyprpwcenter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libdrm.so:graphics/libdrm \
		libpipewire-0.3.so:multimedia/pipewire \
		libhyprtoolkit.so:x11-toolkits/hyprtoolkit

USES=		cmake pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_XORG=	pixman

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop

.include <bsd.port.mk>
