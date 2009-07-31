# New ports collection makefile for:	xfce4-utils
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-utils
PORTVERSION=	4.6.1
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	xfce-utils-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 essential utilities and scripts

CONFIGURE_ARGS+=--with-xsession-prefix=${PREFIX}
GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel

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
	@${REINPLACE_CMD} 's|/usr/local/share:|${LOCALBASE}/share:|' \
		${WRKSRC}/scripts/startxfce4.in
	@${REINPLACE_CMD} 's|/usr/local/share:||' \
		${WRKSRC}/scripts/startxfce4.in

.include <bsd.port.post.mk>
