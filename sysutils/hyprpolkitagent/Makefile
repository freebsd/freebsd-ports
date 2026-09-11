PORTNAME=	hyprpolkitagent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Polkit authentication agent written in QT/QML
WWW=		https://github.com/hyprwm/hyprpolkitagent

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libbasu.so:devel/basu \
		libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libsdbus-c++.so:devel/sdbus-cpp \
		libhyprgraphics.so:graphics/hyprgraphics \
		libdrm.so:graphics/libdrm \
		libaquamarine.so:x11-toolkits/aquamarine \
		libhyprtoolkit.so:x11-toolkits/hyprtoolkit

USES=		cmake pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_XORG=	pixman

PLIST_FILES=	lib/systemd/user/${PORTNAME}.service \
		libexec/${PORTNAME} \
		share/dbus-1/services/org.hyprland.${PORTNAME}.service

.include <bsd.port.mk>
