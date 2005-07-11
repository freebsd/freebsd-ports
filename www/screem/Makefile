# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION=	0.14.2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice GNOME/GTK-based HTML editor

LIB_DEPENDS=	dbus-1.1:${PORTSDIR}/devel/dbus \
		croco-0.6.3:${PORTSDIR}/textproc/libcroco

USE_X_PREFIX=	yes
USE_GNOME=	desktopfileutils gnomehack gnomemenus gnomeprefix gnometarget \
		gtksourceview intlhack libgnomeprintui libgnomeui libgtkhtml
USE_XPM=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	screem.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|$${DATADIRNAME}/$${PACKAGE}|$${DATADIRNAME}/gnome/$${PACKAGE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\&\& make|\&\& $$(MAKE)|g' ${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
