# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pinentry
PORTVERSION=	0.9.2
PORTREVISION?=	0
CATEGORIES=	security
MASTER_SITES=	GNUPG/pinentry

MAINTAINER=	makc@FreeBSD.org
COMMENT?=	Collection of simple PIN or passphrase entry dialogs

USES=		tar:bzip2

.if !defined(PINENTRY_GUI)
INFO=		pinentry
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/pinentry

OPTIONS_SINGLE=	FRONTEND
OPTIONS_SINGLE_FRONTEND=	TTY NCURSES GTK2 QT4
OPTIONS_DEFAULT=	TTY

FRONTEND_DESC=	Default frontend

TTY_DESC=	Console version
PINENTRY_TTY=	pinentry-tty
TTY_RUN_DEPENDS=	${PINENTRY_TTY}:${PORTSDIR}/security/pinentry-tty

NCURSES_DESC=	Curses frontend
PINENTRY_NCURSES=	pinentry-curses
NCURSES_RUN_DEPENDS=	${PINENTRY_NCURSES}:${PORTSDIR}/security/pinentry-curses

GTK2_DESC=	Gtk+ 2 frontend
PINENTRY_GTK2=	pinentry-gtk-2
GTK2_RUN_DEPENDS=	${PINENTRY_GTK2}:${PORTSDIR}/security/pinentry-gtk2

.if exists(/usr/lib/libc++.so)
QT4_DESC=	Qt 4 frontend (broken)
.else
QT4_DESC=	Qt 4 frontend
.endif
PINENTRY_QT4=	pinentry-qt4
QT4_RUN_DEPENDS=	${PINENTRY_QT4}:${PORTSDIR}/security/pinentry-qt4

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
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libksba.so:${PORTSDIR}/security/libksba

USES+=		iconv gmake pkgconfig
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	LIBSECRET

LIBSECRET_DESC=	Saving the passphrase with libsecret
LIBSECRET_CONFIGURE_ENABLE=	libsecret
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:${PORTSDIR}/security/libsecret

.if ${PINENTRY_GUI} == "qt4"
USES+=		compiler:c++11-lib
USE_CXXSTD=	c++11
. if exists(/usr/lib/libc++.so)
IGNORE=		does not compile with libc++
. endif
USE_QT4=	gui moc_build
PLIST_FILES=	bin/pinentry-qt4
.else
CONFIGURE_ARGS+=--disable-pinentry-qt4
.endif

.if ${PINENTRY_GUI} == "gtk2"
OPTIONS_DEFAULT+=	LIBSECRET
USE_GNOME+=	gtk20
PLIST_FILES=	bin/pinentry-gtk-2
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk2
.endif

.if ${PINENTRY_GUI} == "curses"
USES+=		ncurses
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

pre-configure:
.if ${PINENTRY_GUI} == "qt4"
	cd ${WRKSRC}/qt4 && \
		${MOC} pinentrydialog.h > pinentrydialog.moc && \
		${MOC} qsecurelineedit.h > qsecurelineedit.moc && \
		${MOC} pinentryconfirm.h > pinentryconfirm.moc
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/pinentry \
		${STAGEDIR}${PREFIX}/info/pinentry.info

.endif # !defined(PINENTRY_GUI)

.include <bsd.port.mk>
