# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/security/seahorse-plugins/Makefile,v 1.28 2011/07/03 11:57:45 kwm Exp $

PORTNAME=	seahorse-plugins
PORTVERSION=	2.30.1
PORTREVISION=	8
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Seahorse key and password management application

LIB_DEPENDS=	cryptui:${PORTSDIR}/security/seahorse \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	intlhack gnomeprefix gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NAUTILUS GEDIT APPLET NOTIFY
OPTIONS_DEFAULT=NAUTILUS GEDIT APPLET NOTIFY
NAUTILUS_DESC=	Nautilus component
GEDIT_DESC=	GEdit plug-in support
APPLET_DESC=	Clipboard encryption applet

GCONF_SCHEMAS=	seahorse-plugins.schemas
MAN1=		seahorse-agent.1 seahorse-tool.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEDIT}
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
GCONF_SCHEMAS+=	seahorse-gedit.schemas
.else
PLIST_SUB+=	GEDIT="@comment "
CONFIGURE_ARGS+=--disable-gedit
.endif

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus2
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--disable-nautilus
.endif

CONFIGURE_ARGS+=--disable-epiphany
PLIST_SUB+=	EPHY="@comment "

.if ${PORT_OPTIONS:MAPPLET}
USE_GNOME+=	gnomepanel
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-applet
PLIST_SUB+=	APPLET="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
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

.include <bsd.port.mk>
