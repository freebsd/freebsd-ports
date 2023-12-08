PORTNAME=	kooha
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.4
PORTREVISION=	2
CATEGORIES=	multimedia wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Elegantly record your screen
WWW=		https://github.com/SeaDve/Kooha

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libgraphene-1.0.so:graphics/graphene
RUN_DEPENDS=	${LOCALBASE}/lib/gstreamer-1.0/libgstgtk4.so:multimedia/gstreamer1-plugins-rust

USES=		cargo gettext gnome gstreamer meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	good opus pulse vpx
GH_ACCOUNT=	SeaDve
GH_PROJECT=	Kooha
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	io.github.seadve.Kooha.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		-e '/pulse/s/15\.0/14.0/' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'src',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
