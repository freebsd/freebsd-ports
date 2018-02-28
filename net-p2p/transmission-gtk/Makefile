# $FreeBSD$

PKGNAMESUFFIX=	-gtk

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Fast and lightweight GTK+3 BitTorrent client

LIB_DEPENDS=	${GEN_LIB_DEPENDS} \
		libnotify.so:devel/libnotify \
		libdbus-glib-1.so:devel/dbus-glib

RUN_DEPENDS=	${GEN_RUN_DEPENDS} \
		xdg-open:devel/xdg-utils

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	gtk

USE_GNOME=	cairo gtk30 intlhack
USES=		gettext pathfix desktop-file-utils
INSTALLS_ICONS=	yes

EXTRA_CONF_ARGS=--disable-cli \
		--disable-daemon \
		--with-gtk \
		--disable-mac \
		--enable-nls

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|TryExec=.*||g ; /^$$/d' \
		${WRKSRC}/gtk/transmission-gtk.desktop.in

.include "${MASTERDIR}/Makefile"
