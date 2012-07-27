# New ports collection makefile for:	pinentry
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	pinentry
PORTVERSION=	0.8.1
PORTREVISION?=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	pinentry

MAINTAINER=	makc@FreeBSD.org
COMMENT?=	A collection of simple PIN or passphrase entry dialogs

LIB_DEPENDS=	gcrypt.18:${PORTSDIR}/security/libgcrypt \
		ksba.19:${PORTSDIR}/security/libksba

CONFLICTS_INSTALL?=	pinentry-[a-z]*-[0.9]*

USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INFO=		pinentry

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(PINENTRY_SLAVE)
OPTIONS_MULTI=	FRONTEND
OPTIONS_MULTI_FRONTEND=	NCURSES GTK GTK2 QT3 QT4
OPTIONS_DEFAULT=	${OPTIONS_MULTI_FRONTEND}

NCURSES_DESC=	Curses frontend
GTK_DESC=	Gtk+1 frontend
GTK2_DESC=	Gtk+2 frontend
QT3_DESC=	Qt3 frontend
QT4_DESC=	Qt4 frontend
.else
PKGNAMESUFFIX=	${PINENTRY_SLAVE}
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT3}
USE_QT_VER=	3
PLIST_SUB+=	WITH_QT3=""
MOC3=		${LOCALBASE}/bin/moc
.else
CONFIGURE_ARGS+=--disable-pinentry-qt
PLIST_SUB+=	WITH_QT3="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	gui moc_build
PLIST_SUB+=	WITH_QT4=""
MOC4=		${LOCALBASE}/bin/moc-qt4
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=--disable-pinentry-qt4
PLIST_SUB+=	WITH_QT4="@comment "
.endif

.if ${PORT_OPTIONS:MGTK}
USE_GNOME+=	gtk12
PLIST_SUB+=	WITH_GTK=""
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk
PLIST_SUB+=	WITH_GTK="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk2
PLIST_SUB+=	WITH_GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MNCURSES}
USE_NCURSES=	yes
PLIST_SUB+=	WITH_NCURSES=""
.else
CONFIGURE_ARGS+=--disable-pinentry-curses
PLIST_SUB+=	WITH_NCURSES="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/m4/qt.m4 ${WRKSRC}/configure
.if ${PORT_OPTIONS:MQT3}
	${REINPLACE_CMD} -e "/^MOC/s,@MOC@,${MOC3}," \
		${WRKSRC}/qt/Makefile.in
.endif
.if ${PORT_OPTIONS:MQT4}
	cd ${WRKSRC}/qt4 && \
		${MOC4} pinentrydialog.h > pinentrydialog.moc && \
		${MOC4} qsecurelineedit.h > qsecurelineedit.moc
.endif

.include <bsd.port.mk>
