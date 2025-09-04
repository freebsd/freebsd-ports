PORTNAME=	gotktrix
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
PORTREVISION=	26
CATEGORIES=	net-im

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Matrix client in Go and GTK4
WWW=		https://github.com/diamondburned/gotktrix

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libharfbuzz.so:print/harfbuzz \
		libvulkan.so:graphics/vulkan-loader

USES=		gnome go:modules pkgconfig
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 introspection pango
GO_MODULE=	github.com/diamondburned/gotktrix

PLIST_FILES=	bin/gotktrix \
		share/icons/hicolor/256x256/apps/gotktrix.png \
		${DESKTOPDIR}/com.github.diamondburned.gotktrix.desktop
post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/.github/logo-256.png \
	    ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/gotktrix.png
	${INSTALL_DATA} ${WRKSRC}/.nix/com.github.diamondburned.gotktrix.desktop \
	    ${STAGEDIR}${DESKTOPDIR}/

.include <bsd.port.mk>
