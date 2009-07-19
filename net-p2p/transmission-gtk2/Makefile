# New ports collection makefile for:	transmission-gtk2
# Date created:				11 February 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A fast and lightweight GTK+2 BitTorrent client

LIB_DEPENDS=	${GEN_LIB_DEPENDS} \
		notify.1:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${GEN_RUN_DEPENDS} \
		xdg-open:${PORTSDIR}/devel/xdg-utils

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	gtk2

USE_GNOME=	gnometarget gnomehack gtk20 desktopfileutils intlhack
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

EXTRA_CONF_ARGS=--disable-cli \
		--disable-daemon \
		--enable-gtk \
		--enable-libnotify \
		--disable-mac \
		--enable-nls

MAN1=		transmission.1

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TryExec=.*||g ; /^$$/d' \
		${WRKSRC}/gtk/transmission.desktop.in

post-install: general-install
	@-update-desktop-database

.include "${MASTERDIR}/Makefile"
