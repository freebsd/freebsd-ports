# New ports collection makefile for:	desktop-data-model
# Date created:		2008-05-28
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	desktop-data-model
PORTVERSION=	1.2.4
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	wahjava@gmail.com
COMMENT=	Engine providing live updates of online data to the desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpcre.pc:${PORTSDIR}/devel/pcre \
		${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/sqlite3.pc:${PORTSDIR}/databases/sqlite3 \
		${LOCALBASE}/libdata/pkgconfig/loudmouth-1.0.pc:${PORTSDIR}/net-im/loudmouth
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		loudmouth-1.0:${PORTSDIR}/net-im/loudmouth

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gtk20 glib20 gnomedesktop gnomevfs2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-maemo=no
USE_XORG=	xscrnsaver

post-patch:
	${REINPLACE_CMD} -e s,%%LOCALBASE%%,${LOCALBASE}, ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
