PORTNAME=	celluloid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK frontend for mpv
WWW=		https://celluloid-player.github.io/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libmpv.so:multimedia/mpv

USES=		compiler:c11 desktop-file-utils gettext-tools gnome \
		meson pkgconfig python:build shebangfix tar:xz
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 gtk40 libadwaita
GH_ACCOUNT=	${PORTNAME}-player
SHEBANG_FILES=	src/generate-authors.py meson-post-install.py
GLIB_SCHEMAS=	io.github.celluloid_player.Celluloid.gschema.xml

.include <bsd.port.mk>
