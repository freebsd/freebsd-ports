# New ports collection makefile for:	thunar
# Date created:		19.04.2006
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Thunar
PORTVERSION=	0.8.0
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITES_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 file manager

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gnomehack gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libexo libutil
USE_XLIB=	yes

OPTIONS=	DBUS	"Enable D-BUS support"		on  \
		JPEG	"Enable JPEG support"		on  \
		FAM	"Enable FAM support"		off \
		GCONF	"Enable GCONF support"		off \
		EXIF	"Enable EXIF support"		off \
		PCRE	"Enable PCRE support"		off \
		STARTUP "Enable startup notification support"	on

MAN1=		Thunar.1

.include  <bsd.port.pre.mk>
.include "${PORTSDIR}/x11-wm/xfce4/bsd.xfce.mk"

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--enable-jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if defined(WITH_FAM)
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin
.endif

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.else
CONFIGURE_ARGS+=--disable-gconf
.endif

.if defined(WITH_EXIF)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=--enable-exif
.else
CONFIGURE_ARGS+=--disable-exif
.endif

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--enable-pcre
.else
CONFIGURE_ARGS+=--disable-pcre
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/docs/Makefile.in
.if !defined(WITH_FAM)
	@${REINPLACE_CMD} -e 's|gamin|no-gamin|g' ${WRKSRC}/configure
.endif

post-install:
	@-update-desktop-database
.include <bsd.port.post.mk>
