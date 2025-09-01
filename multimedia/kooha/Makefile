PORTNAME=	kooha
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	14
CATEGORIES=	multimedia wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Elegantly record your screen
WWW=		https://github.com/SeaDve/Kooha

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo gettext gnome gstreamer meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk40 libadwaita
USE_GSTREAMER=	gl good opus pulse rust vpx
GH_ACCOUNT=	SeaDve
GH_PROJECT=	Kooha
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	io.github.seadve.Kooha.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
