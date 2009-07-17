# New ports collection makefile for:	seahorse-plugins
# Date created:		06 August 2008
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports-stable/security/seahorse-plugins/Makefile,v 1.1 2009/04/15 10:36:03 kwm Exp $
#

PORTNAME=	seahorse-plugins
PORTVERSION=	2.26.2
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
USE_GECKO=	firefox libxul
USE_GNOME=	gnomehack intlhack gnomeprefix libglade2 gconf2 gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	EPIPHANY "Enable Epiphany plug-in support" on \
		NAUTILUS "Enable the Nautilus component" on \
		GEDIT "Enable GEdit plug-in support" on \
		APPLET "Enable clipboard encryption applet" on

GCONF_SCHEMAS=	seahorse-plugins.schemas
MAN1=		seahorse-agent.1 seahorse-tool.1

.include <bsd.port.pre.mk>

.if ${GECKO}=="libxul"
CONFIGURE_ARGS+=--with-gecko=libxul-unstable
.else
CONFIGURE_ARGS+=--with-gecko=${GECKO}
.endif

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

.if !defined(WITHOUT_EPIPHANY)
BUILD_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
RUN_DEPENDS+=	epiphany:${PORTSDIR}/www/epiphany
PLIST_SUB+=	EPIPHANY="" EPHY_VERSION="2.26"
.else
CONFIGURE_ARGS+=--disable-epiphany
PLIST_SUB+=	EPHY="@comment "
.endif

.if !defined(WITHOUT_APPLET)
USE_GNOME+=	gnomepanel
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-applet
PLIST_SUB+=	APPLET="@comment "
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
