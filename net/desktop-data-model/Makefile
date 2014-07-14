# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	desktop-data-model
PORTVERSION=	1.2.4
PORTREVISION=	11
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Engine providing live updates of online data to the desktop

DEPRECATED=	gnome-desktop 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpcre.pc:${PORTSDIR}/devel/pcre \
		${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/sqlite3.pc:${PORTSDIR}/databases/sqlite3 \
		${LOCALBASE}/libdata/pkgconfig/loudmouth-1.0.pc:${PORTSDIR}/net-im/loudmouth
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth

USES=		gettext gmake pkgconfig tar:bzip2
USE_GNOME=	gnomehack gtk20 glib20 gnomedesktop gnomevfs2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-maemo=no
USE_XORG=	xscrnsaver

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e s,%%LOCALBASE%%,${LOCALBASE}, ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
