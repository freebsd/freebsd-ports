# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-utils
PORTVERSION=	4.4.1
PORTREVISION=	0
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITES_XFCE}
DISTNAME=	xfce-utils-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 essential utilities and scripts

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libmcs libutil mcsmanager panel
USE_XLIB=	yes

OPTIONS=	DBUS	"Enable D-BUS support"			on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

post-patch:
.if ${X11BASE} != ${LOCALBASE}
	@${REINPLACE_CMD} 's|/usr/local/share:|${X11BASE}/share:|' \
		${WRKSRC}/scripts/startxfce4.in
.else
	@${REINPLACE_CMD} 's|/usr/local/share:||' \
		${WRKSRC}/scripts/startxfce4.in
.endif

.include <bsd.port.post.mk>
