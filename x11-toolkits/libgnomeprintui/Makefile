# New ports collection makefile for:	libgnomeprintui
# Date created:				12 April 2002
# Whom:					Maxim Sobolev <sobomax@FreBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgnomeprintui/Makefile,v 1.53 2005/09/26 21:14:32 marcus Exp $
#

PORTNAME=	libgnomeprintui
PORTVERSION=	2.12.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprint libgnomecanvas \
		intlhack ltverhack
USE_GETTEXT=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=  libtool:15
USE_BISON=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
