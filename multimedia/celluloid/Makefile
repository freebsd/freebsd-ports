# $FreeBSD$

PORTNAME=	celluloid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple GTK+ frontend for mpv

LICENSE=	GPLv3+

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libmpv.so:multimedia/mpv

USES=		compiler:c11 desktop-file-utils gettext-tools gnome \
		meson pkgconfig python:3.5+,build shebangfix tar:xz
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	${PORTNAME}-player
SHEBANG_FILES=	src/generate-authors.py meson-post-install.py
GLIB_SCHEMAS=	io.github.GnomeMpv.gschema.xml \
		io.github.celluloid_player.Celluloid.gschema.xml
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
