# New ports collection makefile for:	pinentry
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	pinentry
PORTVERSION=	0.8.0
PORTREVISION?=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	pinentry

MAINTAINER=	makc@FreeBSD.org
COMMENT?=	A collection of simple PIN or passphrase entry dialogs

LIB_DEPENDS=	gcrypt.16:${PORTSDIR}/security/libgcrypt \
		ksba.17:${PORTSDIR}/security/libksba

CONFLICTS?=	pinentry-[a-z]*-[0.9]*

USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INFO=		pinentry

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

.if !defined(PINENTRY_SLAVE)
OPTIONS=	NCURSES "Curses frontend" on \
		GTK "Gtk+1 frontend" on \
		GTK2 "Gtk+2 frontend" on \
		QT3 "Qt3 frontend" on \
		QT4 "Qt4 frontend" on
.else
PKGNAMESUFFIX=	${PINENTRY_SLAVE}
.endif

.include <bsd.port.options.mk>

.if !(defined(WITH_NCURSES) || defined(WITH_GTK) || defined(WITH_GTK2) || defined(WITH_QT3) || defined(WITH_QT4))
IGNORE=	requires at least one frontend. Please rerun 'make config'
.endif

.if defined(WITH_QT3)
USE_QT_VER=	3
PLIST_SUB+=	WITH_QT3=""
MOC3=		${LOCALBASE}/bin/moc
.else
CONFIGURE_ARGS+=--disable-pinentry-qt
PLIST_SUB+=	WITH_QT3="@comment "
.endif

.if defined(WITH_QT4)
#USE_QT_VER=	4
#QT_COMPONENTS=	gui moc_build
.include "${PORTSDIR}/Mk/bsd.qt.mk"
BUILD_DEPENDS+=	moc-qt4:${PORTSDIR}/devel/qt4-moc
LIB_DEPENDS+=	QtGui.4:${PORTSDIR}/x11-toolkits/qt4-gui
PLIST_SUB+=	WITH_QT4=""
MOC4=		${LOCALBASE}/bin/moc-qt4
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=--disable-pinentry-qt4
PLIST_SUB+=	WITH_QT4="@comment "
.endif

.if defined(WITH_GTK)
USE_GNOME+=	gtk12
PLIST_SUB+=	WITH_GTK=""
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk
PLIST_SUB+=	WITH_GTK="@comment "
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk2
PLIST_SUB+=	WITH_GTK2="@comment "
.endif

.if defined(WITH_NCURSES)
PLIST_SUB+=	WITH_NCURSES=""
.else
CONFIGURE_ARGS+=--disable-pinentry-curses
PLIST_SUB+=	WITH_NCURSES="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/m4/qt.m4 ${WRKSRC}/configure
.if defined(WITH_QT3)
	${REINPLACE_CMD} -e "/^MOC/s,@MOC@,${MOC3}," \
		${WRKSRC}/qt/Makefile.in
.endif
.if defined(WITH_QT4)
	cd ${WRKSRC}/qt4 && \
		${MOC4} pinentrydialog.h > pinentrydialog.moc && \
		${MOC4} qsecurelineedit.h > qsecurelineedit.moc
.endif

.include <bsd.port.mk>
