PORTNAME=	audacious
DISTVERSION=	4.5
CATEGORIES=	multimedia audio
MASTER_SITES=	https://distfiles.audacious-media-player.org/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Lightweight and versatile audio player
WWW=		https://audacious-media-player.org/

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt6 qt5 gtk3 gtk2
FLAVOR?=	${FLAVORS:[1]}

gtk2_PKGNAMESUFFIX=	-gtk2
gtk2_CONFLICTS_INSTALL=	audacious audacious-gtk3 audacious-qt6

gtk3_PKGNAMESUFFIX=	-gtk3
gtk3_CONFLICTS_INSTALL=	audacious audacious-gtk2 audacious-qt6

qt5_PKGNAMESUFFIX=	-qt5
qt5_CONFLICTS_INSTALL=	audacious-gtk2 audacious-gtk3 audacious-qt6

qt6_CONFLICTS_INSTALL=	audacious audacious-gtk2 audacious-gtk3

USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake gnome \
		iconv localbase meson pkgconfig tar:bzip2 xorg
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_XORG=	sm x11

CONFIGURE_ENV=	LIBRARY_PATH="${LOCALBASE}/lib"
MAKE_ENV=	LIBRARY_PATH="${LOCALBASE}/lib"

SUB_FILES=	pkg-message

.if ${FLAVOR} == qt5
MESON_ARGS+=	-Dgtk2=false \
		-Dgtk=false \
		-Dqt5=true \
		-Dqt=true
USES+=		qt:5
USE_QT=		core gui svg widgets buildtools:build
PLIST_SUB=	GTK="@comment " \
		QT=""
.elif ${FLAVOR} == qt6
MESON_ARGS+=	-Dgtk2=false \
		-Dgtk=false \
		-Dqt5=false \
		-Dqt=true
USES+=		qt:6
USE_QT=		base svg
PLIST_SUB=	GTK="@comment " \
		QT=""
.elif ${FLAVOR} == gtk2
MESON_ARGS+=	-Dgtk2=true \
		-Dgtk=true \
		-Dqt5=false \
		-Dqt=false
USE_GNOME+=	cairo gdkpixbuf gtk20
PLIST_SUB=	GTK="" \
		QT="@comment "
.elif ${FLAVOR} == gtk3
MESON_ARGS+=	-Dgtk2=false \
		-Dgtk=true \
		-Dqt5=false \
		-Dqt=false
USE_GNOME+=	cairo gdkpixbuf gtk30
PLIST_SUB=	GTK="" \
		QT="@comment "
.endif

OPTIONS_DEFINE=		EXECINFO LIBARCHIVE NLS
OPTIONS_DEFAULT=	EXECINFO
OPTIONS_SUB=		yes

EXECINFO_DESC=		Build with libexecinfo support
LIBARCHIVE_DESC=	Build with libarchive support

LIBARCHIVE_USES=	libarchive
LIBARCHIVE_MESON_TRUE=	libarchive

NLS_USES=	gettext-runtime

post-patch-EXECINFO-on:
	@${REINPLACE_CMD} 's|-lm |-lm -lexecinfo |' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -lexecinfo|' \
		${WRKSRC}/audacious.pc.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/contrib/audacious.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo/

.include <bsd.port.mk>
