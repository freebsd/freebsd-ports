PORTNAME=	waynergy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.15
PORTREVISION=	1
CATEGORIES=	sysutils wayland

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility
WWW=		https://github.com/r-c-f/waynergy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libtls.so:security/libretls

USES=	meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	r-c-f

PLIST_FILES=	bin/waynergy \
		bin/waynergy-clip-update \
		bin/waynergy-mapper \
		share/applications/waynergy.desktop

.include <bsd.port.mk>
