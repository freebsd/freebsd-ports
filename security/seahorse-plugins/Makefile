# New ports collection makefile for:	seahorse-plugins
# Date created:		06 August 2008
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports/security/seahorse-plugins/Makefile,v 1.25 2010/04/27 22:22:07 kwm Exp $
#

PORTNAME=	seahorse-plugins
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Seahorse key and password management application

LIB_DEPENDS=	cryptui.0:${PORTSDIR}/security/seahorse

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
#USE_GECKO=	libxul
USE_GNOME=	gnomehack intlhack gnomeprefix gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	NAUTILUS "Enable the Nautilus component" on \
		GEDIT "Enable GEdit plug-in support" on \
		APPLET "Enable clipboard encryption applet" on \
		NOTIFY "Enable libnotify support" on
#EPIPHANY "Enable Epiphany plug-in support" on

GCONF_SCHEMAS=	seahorse-plugins.schemas
MAN1=		seahorse-agent.1 seahorse-tool.1

.include <bsd.port.pre.mk>

#.if ${GECKO}=="libxul"
#CONFIGURE_ARGS+=--with-gecko=libxul-unstable
#.else
#CONFIGURE_ARGS+=--with-gecko=${GECKO}
#.endif

.if !defined(WITHOUT_GEDIT)
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
GCONF_SCHEMAS+=	seahorse-gedit.schemas
.else
PLIST_SUB+=	GEDIT="@comment "
CONFIGURE_ARGS+=--disable-gedit
.endif

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=	nautilus2
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--disable-nautilus
.endif

#.if !defined(WITHOUT_EPIPHANY)
#BUILD_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
#RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
#PLIST_SUB+=	EPIPHANY="" EPHY_VERSION="2.26"
#.else
CONFIGURE_ARGS+=--disable-epiphany
PLIST_SUB+=	EPHY="@comment "
#.endif

.if !defined(WITHOUT_APPLET)
USE_GNOME+=	gnomepanel
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-applet
PLIST_SUB+=	APPLET="@comment "
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' \
		-e 's|epiphany-2.24|epiphany-2.26|g' \
		-e 's|2.24|2.26|g' \
			${WRKSRC}/configure

post-install:
	@-update-desktop-database
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
