# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION=	0.16.1
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice GNOME/GTK-based HTML editor

LIB_DEPENDS=	croco-0.6.3:${PORTSDIR}/textproc/libcroco

USE_X_PREFIX=	yes
USE_GNOME=	desktopfileutils gnomehack gnomemenus gnomeprefix gnometarget \
		gtksourceview intlhack libgnomeprintui libgnomeui libgtkhtml
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	screem.schemas

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.2:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
.endif

.if defined(WITHOUT_ENCHANT)
CONFIGURE_ARGS+=	--disable-enchant
.else
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-enchant
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${DATADIRNAME}/$${PACKAGE}|$${DATADIRNAME}/gnome/$${PACKAGE}|g ; \
		s|-DGNOME_DISABLE_DEPRECATED||g ; \
		s|-DGNOMEUI_DISABLE_DEPRECATED||g ; \
		s|-DGTK_DISABLE_DEPRECATED||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\&\& make|\&\& $$(MAKE)|g' ${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
