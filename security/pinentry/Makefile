# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pinentry
PORTVERSION=	0.9.0
PORTREVISION?=	0
CATEGORIES=	security
MASTER_SITES=	GNUPG/pinentry

MAINTAINER=	makc@FreeBSD.org
COMMENT?=	Collection of simple PIN or passphrase entry dialogs

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libksba.so:${PORTSDIR}/security/libksba

CONFLICTS_INSTALL?=	pinentry-[a-z]*

USES=		iconv gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INFO=		pinentry

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(PINENTRY_SLAVE)
OPTIONS_MULTI=	FRONTEND
OPTIONS_MULTI_FRONTEND=	NCURSES GTK2 QT4
OPTIONS_DEFAULT=	${PINENTRY_DEFAULT}

NCURSES_DESC=	Curses frontend
GTK2_DESC=	Gtk+ 2 frontend
QT4_DESC=	Qt 4 frontend
.else
PKGNAMESUFFIX=	${PINENTRY_SLAVE}
.endif

.include <bsd.port.options.mk>

.if !defined(PINENTRY_SLAVE)
. if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
PINENTRY_DEFAULT=	${OPTIONS_MULTI_FRONTEND:NQT4}
QT4_DESC=	Qt 4 frontend (broken)
. else
PINENTRY_DEFAULT=	${OPTIONS_MULTI_FRONTEND}
. endif
.endif

.if ${PORT_OPTIONS:MQT4}
. if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
IGNORE=		with Qt 4 frontend does not compile with libc++
. endif
USE_QT4=	gui moc_build
PLIST_SUB+=	WITH_QT4=""
MOC4=		${LOCALBASE}/bin/moc-qt4
.else
CONFIGURE_ARGS+=--disable-pinentry-qt4
PLIST_SUB+=	WITH_QT4="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk2
PLIST_SUB+=	WITH_GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MNCURSES}
USES+=		ncurses
PLIST_SUB+=	WITH_NCURSES=""
.else
CONFIGURE_ARGS+=--disable-pinentry-curses
PLIST_SUB+=	WITH_NCURSES="@comment "
.endif

pre-configure:
.if ${PORT_OPTIONS:MQT4}
	cd ${WRKSRC}/qt4 && \
		${MOC4} pinentrydialog.h > pinentrydialog.moc && \
		${MOC4} qsecurelineedit.h > qsecurelineedit.moc && \
		${MOC4} pinentryconfirm.h > pinentryconfirm.moc
.endif

.include <bsd.port.mk>
