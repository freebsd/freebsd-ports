PORTNAME=	audacious
PORTVERSION=	4.3.1
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	https://distfiles.audacious-media-player.org/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Lightweight and versatile audio player
WWW=		https://audacious-media-player.org/

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

FLAVORS=	qt5 qt6 gtk2 gtk3
FLAVOR?=	${FLAVORS:[1]}

USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake \
		gnome iconv localbase meson pkgconfig tar:bzip2 xorg
USE_GNOME=	glib20
USE_XORG=	x11 sm
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

CONFIGURE_ENV=		LIBRARY_PATH="${LOCALBASE}/lib"
MAKE_ENV=		LIBRARY_PATH="${LOCALBASE}/lib"

qt5_CONFLICTS_INSTALL=	audacious-qt6 audacious-gtk2 audacious-gtk3

qt6_PKGNAMESUFFIX=	-qt6
qt6_CONFLICTS_INSTALL=	audacious audacious-gtk2 audacious-gtk3

gtk2_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
gtk2_PKGNAMESUFFIX=	-gtk2
gtk2_CONFLICTS_INSTALL=	audacious audacious-qt6 audacious-gtk3

gtk3_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
gtk3_PKGNAMESUFFIX=	-gtk3
gtk3_CONFLICTS_INSTALL=	audacious audacious-qt6 audacious-gtk2

.if ${FLAVOR} == qt5
MESON_ARGS+=		-Dqt=true -Dqt6=false -Dgtk=false -Dgtk3=false
USES+=			qt:5
USE_QT=			buildtools:build core gui widgets
PLIST_SUB=		QT="" GTK="@comment "
.elif ${FLAVOR} == qt6
MESON_ARGS+=		-Dqt=true -Dqt6=true -Dgtk=false -Dgtk3=false
USES+=			qt:6
USE_QT=			base
PLIST_SUB=		QT="" GTK="@comment "
.elif ${FLAVOR} == gtk2
MESON_ARGS+=		-Dqt=false -Dqt6=false -Dgtk=true -Dgtk3=false
USE_GNOME+=		cairo gdkpixbuf2 gtk20
PLIST_SUB=		QT="@comment " GTK=""
.elif ${FLAVOR} == gtk3
MESON_ARGS+=		-Dqt=false -Dqt6=false -Dgtk=true -Dgtk3=true
USE_GNOME+=		cairo gdkpixbuf2 gtk30
PLIST_SUB=		QT="@comment " GTK=""
.endif

OPTIONS_DEFINE=		NLS LIBARCHIVE EXECINFO
OPTIONS_DEFAULT=	EXECINFO
OPTIONS_SUB=		yes
EXECINFO_DESC=		Build with libexecinfo support
LIBARCHIVE_DESC=	Build with libarchive support

LIBARCHIVE_MESON_TRUE=	libarchive
LIBARCHIVE_USES=	libarchive

NLS_USES=		gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

post-patch-EXECINFO-on:
	@${REINPLACE_CMD} 's|-lm |-lm -lexecinfo |' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -lexecinfo|' \
		${WRKSRC}/audacious.pc.in

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/contrib/audacious.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo/

.include <bsd.port.mk>
