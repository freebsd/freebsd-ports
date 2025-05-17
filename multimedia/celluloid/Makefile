PORTNAME=	celluloid
DISTVERSION=	0.29
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/${PORTNAME}-player/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple GTK frontend for mpv
WWW=		https://celluloid-player.github.io/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libmpv.so:multimedia/mpv

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson \
		pkgconfig python:build shebangfix tar:xz
USE_GNOME=	gdkpixbuf gtk40 libadwaita
GLIB_SCHEMAS=	io.github.celluloid_player.Celluloid.gschema.xml
SHEBANG_FILES=	meson-post-install.py src/generate-authors.py

do-test:
	cd ${BUILD_WRKSRC} &&  ${DO_MAKE_BUILD} test

.include <bsd.port.mk>
