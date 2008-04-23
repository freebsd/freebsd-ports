# New ports collection makefile for:   gnomenetstatus
# Date Created:			05 December 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/gnome-netstatus/Makefile,v 1.48 2007/07/04 21:42:20 marcus Exp $
#

PORTNAME=	gnome-netstatus
PORTVERSION=	2.12.1
PORTREVISION=	6
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME applet that shows network status

INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehack intlhack gnomeprefix libgnome gnomepanel libglade2 \
		gnomedocutils
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	netstatus.schemas

.include <bsd.port.mk>
