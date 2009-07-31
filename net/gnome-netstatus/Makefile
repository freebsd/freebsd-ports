# New ports collection makefile for:   gnomenetstatus
# Date Created:			05 December 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/gnome-netstatus/Makefile,v 1.52 2009/03/08 19:32:04 marcus Exp $
#

PORTNAME=	gnome-netstatus
PORTVERSION=	2.26.0
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME applet that shows network status

INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnome gnomepanel libglade2 \
		gnomedocutils
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	netstatus.schemas

.include <bsd.port.mk>
