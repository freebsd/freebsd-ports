PORTNAME=	clapper
DISTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	multimedia wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and modern GNOME media player
WWW=		https://rafostar.github.io/clapper

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gjs:lang/gjs
RUN_DEPENDS=	gjs:lang/gjs

USES=		desktop-file-utils gettext-tools gl gnome gstreamer meson \
		pkgconfig python:build shared-mime-info shebangfix
USE_GITHUB=	yes
USE_GL=		glesv2
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	gl good libav
USE_LDCONFIG=	yes
GH_ACCOUNT=	Rafostar
SHEBANG_FILES=	build-aux/meson/postinstall.py
GLIB_SCHEMAS=	com.github.rafostar.Clapper.gschema.xml

post-patch:
# Derive Python version from Meson
	@${REINPLACE_CMD} -e "s,'python3',," ${WRKSRC}/meson.build

.include <bsd.port.mk>
