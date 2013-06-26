# $FreeBSD$

PKGNAMESUFFIX=	-gtk

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Fast and lightweight GTK+2 BitTorrent client

LIB_DEPENDS=	${GEN_LIB_DEPENDS} \
		notify:${PORTSDIR}/devel/libnotify \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

RUN_DEPENDS=	${GEN_RUN_DEPENDS} \
		xdg-open:${PORTSDIR}/devel/xdg-utils

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	gtk

USE_GNOME=	gtk30 desktopfileutils intlhack
USES=		gettext pathfix
INSTALLS_ICONS=	yes

EXTRA_CONF_ARGS=--disable-cli \
		--disable-daemon \
		--with-gtk \
		--enable-inotify \
		--disable-mac \
		--enable-nls

MAN1=		transmission-gtk.1

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TryExec=.*||g ; /^$$/d' \
		${WRKSRC}/gtk/transmission-gtk.desktop.in

post-install: general-install
	@-update-desktop-database

.include "${MASTERDIR}/Makefile"
