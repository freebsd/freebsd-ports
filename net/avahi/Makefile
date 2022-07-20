PORTNAME=	avahi
PORTVERSION=	0.8
CATEGORIES?=	net dns

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the Avahi service discovery suite

RUN_DEPENDS=	avahi-app>=0.8:net/avahi-app

USES=		metaport

OPTIONS_DEFINE=	AUTOIPD GTK2 GTK3 MONO QT5 PYTHON
OPTIONS_DEFAULT=AUTOIPD GTK3
AUTOIPD_DESC=	IPv4LL network address configuration daemon
LIBDNS_DESC=	Apple's mDNSResponder compatibility library

AUTOIPD_RUN_DEPENDS=	avahi-autoipd:net/avahi-autoipd
GTK2_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/avahi-ui.pc:net/avahi-gtk
GTK3_RUN_DEPENDS=	avahi-discover-standalone:net/avahi-gtk3
#LIBDNS_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/avahi-compat-libdns_sd.pc:net/avahi-libdns
MONO_RUN_DEPENDS=	${LOCALBASE}/lib/mono/avahi-sharp/avahi-sharp.dll:net/avahi-sharp
QT5_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/avahi-qt5.pc:net/avahi-qt5
PYTHON_RUN_DEPENDS=	avahi-bookmarks:net/py-avahi

.include <bsd.port.mk>
