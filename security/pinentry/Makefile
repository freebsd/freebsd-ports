PORTNAME=	pinentry
PORTVERSION=	1.3.2
PORTREVISION?=	0
CATEGORIES=	security
MASTER_SITES=	GNUPG/pinentry

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Collection of simple PIN or passphrase entry dialogs
WWW=		https://www.gnupg.org/aegypten2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2

.if !defined(PINENTRY_GUI)
INFO=		pinentry
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/pinentry

OPTIONS_SINGLE=	FRONTEND
OPTIONS_SINGLE_FRONTEND=	EFL FLTK GNOME GTK2 NCURSES QT5 QT6 TTY
OPTIONS_DEFAULT=	NCURSES

FRONTEND_DESC=	Default frontend

TTY_DESC=	Console version
PINENTRY_TTY=	pinentry-tty
TTY_RUN_DEPENDS=	${PINENTRY_TTY}:security/pinentry-tty

NCURSES_DESC=	Curses frontend
PINENTRY_NCURSES=	pinentry-curses
NCURSES_RUN_DEPENDS=	${PINENTRY_NCURSES}:security/pinentry-curses

EFL_DESC=	EFL frontend
PINENTRY_EFL=	pinentry-efl
# Due to a dependency loop that exists between security/pinentry-efl,
# devel/elf, graphics/poppler, security/gpgmepp, security/gpgme,
# security/gnupg and security/pinentry, the user must install
# pinentry-efl manually. See pkg-message.dep-loop for more details.
#EFL_RUN_DEPENDS=	${PINENTRY_EFL}:security/pinentry-efl
EFL_SUB_FILES=	pkg-message.dep-loop
EFL_SUB_LIST=	PKGNAME="pinentry-efl"
EFL_VARS=	PKGMESSAGE+=${WRKDIR}/pkg-message.dep-loop

FLTK_DESC=	FLTK frontend
PINENTRY_FLTK=	pinentry-fltk
FLTK_RUN_DEPENDS=	${PINENTRY_FLTK}:security/pinentry-fltk

GTK2_DESC=	Gtk+ 2 frontend
PINENTRY_GTK2=	pinentry-gtk-2
GTK2_RUN_DEPENDS=	${PINENTRY_GTK2}:security/pinentry-gtk2

QT5_DESC=	Qt 5 frontend
PINENTRY_QT5=	pinentry-qt5
QT5_RUN_DEPENDS=	${PINENTRY_QT5}:security/pinentry-qt5

QT6_DESC=	Qt 6 frontend
PINENTRY_QT6=	pinentry-qt
QT6_RUN_DEPENDS=	${PINENTRY_QT6}:security/pinentry-qt6

GNOME_DESC=	GNOME frontend
PINENTRY_GNOME=	pinentry-gnome3
# Due to a dependency loop that exists between security/pinentry-gnome,
# security/gcr, security/gnupg and security/pinentry, the user must install
# pinentry-gnome manually. See pkg-message.dep-loop for more details.
#GNOME_RUN_DEPENDS=	${PINENTRY_GNOME}:security/pinentry-gnome
GNOME_SUB_FILES=pkg-message.dep-loop
GNOME_SUB_LIST=	PKGNAME="pinentry-gnome"
GNOME_VARS=	PKGMESSAGE+=${WRKDIR}/pkg-message.dep-loop

.include <bsd.port.options.mk>

.for gui in ${OPTIONS_SINGLE_FRONTEND}
. if ${PORT_OPTIONS:M${gui}}
PINENTRY_BIN=	${PINENTRY_${gui}}
. endif
.endfor

do-install:
	${LN} -sf ${PINENTRY_BIN} ${STAGEDIR}${PREFIX}/bin/pinentry
	${INSTALL_DATA} ${WRKSRC}/doc/pinentry.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.else # !defined(PINENTRY_GUI)
PKGNAMESUFFIX=	-${PINENTRY_GUI}
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error

USES+=		gmake iconv localbase ncurses pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-pinentry-emacs
LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=	LIBSECRET

LIBSECRET_DESC=	Saving the passphrase with libsecret
LIBSECRET_CONFIGURE_ENABLE=	libsecret
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_USES=		gnome
LIBSECRET_USE=		GNOME=glib20

.if ${PINENTRY_GUI} == "gnome"
OPTIONS_SLAVE=	LIBSECRET
LIB_DEPENDS+=	libgcr-base-3.so:security/gcr3
PLIST_FILES=	bin/pinentry-gnome3
.else
CONFIGURE_ARGS+=--disable-pinentry-gnome3
.endif

.if ${PINENTRY_GUI} == "qt5"
USES+=		compiler:c++11-lang kde:5 qt:5 xorg
USE_KDE=	wayland
USE_QT=		core gui widgets x11extras buildtools:build
USE_XORG=	x11
PLIST_FILES=	bin/pinentry-qt5 \
		share/applications/org.gnupg.pinentry-qt5.desktop \
		share/pixmaps/pinentry-qt5.png
CONFIGURE_ARGS+=--enable-pinentry-qt5
.else
CONFIGURE_ARGS+=--disable-pinentry-qt5
.endif

.if ${PINENTRY_GUI} == "qt6"
USES+=		compiler:c++17-lang kde:6 qt:6
USE_CXXSTD=	c++17
USE_KDE=	guiaddons windowsystem
USE_QT=		base
PLIST_FILES=	bin/pinentry-qt \
		share/applications/org.gnupg.pinentry-qt.desktop \
		share/pixmaps/pinentry.png
CONFIGURE_ARGS+=--enable-pinentry-qt
.else
CONFIGURE_ARGS+=--disable-pinentry-qt
.endif

.if ${PINENTRY_GUI} == "gtk2"
USES+=		gnome
USE_GNOME+=	gtk20
PLIST_FILES=	bin/pinentry-gtk-2
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk2
.endif

.if ${PINENTRY_GUI} == "efl"
LIB_DEPENDS+=	libefl.so:devel/efl
PLIST_FILES=	bin/pinentry-efl
.else
CONFIGURE_ARGS+=--disable-pinentry-efl
.endif

.if ${PINENTRY_GUI} == "fltk"
USES+=		compiler:c++11-lib
LIB_DEPENDS+=	libfltk.so:x11-toolkits/fltk
PLIST_FILES=	bin/pinentry-fltk
.else
CONFIGURE_ARGS+=--disable-pinentry-fltk
.endif

.if ${PINENTRY_GUI} == "curses"
PLIST_FILES=	bin/pinentry-curses
.else
CONFIGURE_ARGS+=--disable-pinentry-curses
.endif

.if ${PINENTRY_GUI} == "tty"
PLIST_FILES=	bin/pinentry-tty
CONFIGURE_ARGS+=--enable-pinentry-tty
.else
CONFIGURE_ARGS+=--disable-pinentry-tty
.endif

# Rename icon to prevent install conflicts with the Qt6 frontend.
post-extract:
	@(cd ${WRKSRC}/qt5/icons && ${MV} pinentry.png pinentry-qt5.png)

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/pinentry \
		${STAGEDIR}${PREFIX}/share/info/pinentry.info

.endif # !defined(PINENTRY_GUI)

.include <bsd.port.mk>
