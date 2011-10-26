# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	libxfce4gui
PORTVERSION=	4.8.1
CATEGORIES=	x11-toolkits xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/libxfcegui4/${PORTVERSION:R}
DISTNAME=	libxfcegui4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 widget library required by Xfce4 and Xfwm4

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 intltool intlhack libglade2 pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil
USE_XORG=	sm x11

OPTIONS=	NLS	"Enable Native Language Support"	on  \
		STARTUP	"Use libstartup-notification"		on  \
		GLADEUI	"Glade interface designer"		off \
		APIDOCS	"Install api documentation"		off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_LIBSTARTUP)
LIB_DEPENDS+=	startup-notification-1:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if defined(WITH_GLADEUI)
LIB_DEPENDS+=	gladeui-1.10:${PORTSDIR}/devel/glade3
CONFIGURE_ARGS+=--enable-gladeui
PLIST_SUB+=	GLADE3=""
.else
CONFIGURE_ARGS+=--disable-gladeui
PLIST_SUB+=	GLADE3="@comment "
.endif

.if defined(WITHOUT_APIDOCS)
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.endif
post-patch:
	@${REINPLACE_CMD} -e 's|$$(GMSGFMT)|$$(MSGFMT)|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.post.mk>
