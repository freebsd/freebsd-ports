# New ports collection makefile for:	pinentry
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	pinentry
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	pinentry

MAINTAINER=	lofi@freebsd.org
COMMENT?=	A collection of simple PIN or passphrase entry dialogs

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt \
		ksba.15:${PORTSDIR}/security/libksba

CONFLICTS?=	pinentry-[a-z]*-[0.9]*

USE_GETOPT_LONG=yes
USE_ICONV=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
INFO=		pinentry

CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE}

.if defined(PINENTRY_QT) || defined(PINENTRY_GTK) || defined(PINENTRY_GTK2) || defined(PINENTRY_CURSES)
.if defined(PINENTRY_QT)
USE_QT_VER=	3
PLIST_SUB+=	WITH_QT=""

pre-configure:
	@${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/configure

.else
CONFIGURE_ARGS+=--disable-pinentry-qt
PLIST_SUB+=	WITH_QT="@comment "
.endif

.if defined(PINENTRY_GTK)
USE_GNOME+=	gtk12
PLIST_SUB+=	WITH_GTK=""
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk
PLIST_SUB+=	WITH_GTK="@comment "
.endif

.if defined(PINENTRY_GTK2)
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--disable-pinentry-gtk2
PLIST_SUB+=	WITH_GTK2="@comment "
.endif

.if defined(PINENTRY_CURSES)
PLIST_SUB+=	WITH_CURSES=""
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-pinentry-curses
PLIST_SUB+=	WITH_CURSES="@comment "
.endif
.else
USE_QT_VER=	3
USE_GNOME+=	gtk12 gtk20
PLIST_SUB+=	WITH_QT=""
PLIST_SUB+=	WITH_GTK=""
PLIST_SUB+=	WITH_GTK2=""
PLIST_SUB+=	WITH_CURSES=""
.endif

.include <bsd.port.mk>
