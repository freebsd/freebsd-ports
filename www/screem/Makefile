# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	screem
PORTVERSION=	0.16.1
PORTREVISION=	14
CATEGORIES=	www gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice GNOME/GTK-based HTML editor

DEPRECATED=	gnome-menus 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

LIB_DEPENDS=	croco-0.6.3:${PORTSDIR}/textproc/libcroco

USES=		pathfix pkgconfig gettext gmake
USE_GNOME=	desktopfileutils gnomemenus gnomeprefix \
		gtksourceview intlhack libgnomeprintui libgnomeui libgtkhtml
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	screem.schemas

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
.endif

.if defined(WITHOUT_ENCHANT)
CONFIGURE_ARGS+=	--disable-enchant
.else
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-enchant
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-DGNOME_DISABLE_DEPRECATED||g ; \
		s|-DGNOMEUI_DISABLE_DEPRECATED||g ; \
		s|-DGTK_DISABLE_DEPRECATED||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\&\& make|\&\& $$(MAKE)|g' \
		${WRKSRC}/tests/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/include/screem-markup.h \
		${WRKSRC}/include/screem-mdi.h \
		${WRKSRC}/include/screem-tagtree.h \
		${WRKSRC}/libegg/util/egg-macros.h \
		${WRKSRC}/src/screem-cvs.c \
		${WRKSRC}/src/screem-dtd-db.c \
		${WRKSRC}/src/screem-file-browser.c \
		${WRKSRC}/src/screem-markup.c \
		${WRKSRC}/src/screem-site-parse.c
	@${REINPLACE_CMD} -e 's|glib/glist.h>|glib.h>|g' \
		-e 's|glib/gconvert.h>|glib.h>|g' \
		-e 's|glib/gunicode.h>|glib.h>|g' \
		-e 's|glib/gstrfuncs.h>|glib.h>|g' \
		-e 's|glib/gfileutils.h>|glib.h>|g' \
		-e 's|glib/ghash.h>|glib.h>|g' \
		${WRKSRC}/plugins/entityWizard/entityWizard.c \
		${WRKSRC}/src/screem-mdi.c \
		${WRKSRC}/src/screem-page.c \
		${WRKSRC}/src/screem-search.c \
		${WRKSRC}/src/screem-site-ui.c \
		${WRKSRC}/src/screem-site.c \
		${WRKSRC}/src/screem-window-menus.c \
		${WRKSRC}/src/fileops.c \
		${WRKSRC}/src/support.c

.include <bsd.port.mk>
