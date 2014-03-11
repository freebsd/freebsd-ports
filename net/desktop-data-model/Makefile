# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	desktop-data-model
PORTVERSION=	1.2.4
PORTREVISION=	10
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
LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		loudmouth-1.0:${PORTSDIR}/net-im/loudmouth

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehack gtk20 glib20 gnomedesktop gnomevfs2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-maemo=no
USE_XORG=	xscrnsaver

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e s,%%LOCALBASE%%,${LOCALBASE}, ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
