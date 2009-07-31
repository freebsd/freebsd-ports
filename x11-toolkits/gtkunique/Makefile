# New ports collection makefile for:	GtkUnique
# Date created:				21 Mar 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkunique
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DIST_SUBDIR=	gnome2

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Single instance application library

USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_GNOME=	gtk20 ltverhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	DBUS "D-Bus backend" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DBUS)
PLIST_SUB+=	DBUS="@comment " XLIBS=""
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	DBUS="" XLIBS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
