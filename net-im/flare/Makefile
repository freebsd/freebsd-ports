PORTNAME=	flare
DISTVERSION=	0.16.3
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Electron-free Signal app written in Rust
WWW=		https://gitlab.com/schmiddi-on-mobile/flare

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler \
		protoc:devel/protobuf
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	gnome-keyring:security/gnome-keyring

USES=		cargo gettext-tools gnome meson pkgconfig python:build
USE_GITLAB=	yes
GL_ACCOUNT=	schmiddi-on-mobile
USE_GNOME=	cairo gdkpixbuf gtk40 gtksourceview5 libadwaita libxml2 pango
GLIB_SCHEMAS=	de.schmidhuberj.Flare.gschema.xml

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

OPTIONS_DEFINE=		FEEDBACK SPELLCHECK
FEEDBACK_DESC=		for vibrating notifications
SPELLCHECK_DESC=	for spell-checking support
FEEDBACK_LIB_DEPENDS=	libfeedback-0.0.so:accessibility/feedbackd
SPELLCHECK_LIB_DEPENDS=	libspelling-1.so:x11-toolkits/libspelling

post-patch:
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'target',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/system-services \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/symbolic/apps \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_PROGRAM} ${WRKSRC}/_build/target/release/flare \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/_build/data/de.schmidhuberj.Flare.desktop \
		${STAGEDIR}${DESKTOPDIR}/de.schmidhuberj.Flare.desktop
	${INSTALL_DATA} ${WRKSRC}/_build/data/de.schmidhuberj.Flare.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/system-services/de.schmidhuberj.Flare.service
	${INSTALL_DATA} ${WRKSRC}/data/de.schmidhuberj.Flare.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/de.schmidhuberj.Flare.gschema.xml
	${INSTALL_DATA} ${WRKSRC}/data/icons/de.schmidhuberj.Flare.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/de.schmidhuberj.Flare.svg
	${INSTALL_DATA} ${WRKSRC}/data/icons/de.schmidhuberj.Flare-symbolic.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/symbolic/apps/de.schmidhuberj.Flare-symbolic.svg
	${INSTALL_DATA} ${WRKSRC}/_build/data/de.schmidhuberj.Flare.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo/de.schmidhuberj.Flare.metainfo.xml

.include <bsd.port.mk>
