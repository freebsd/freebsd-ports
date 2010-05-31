# New ports collection makefile for:	gnome-themes
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes/Makefile,v 1.178 2010/04/29 12:44:55 kwm Exp $
#

PORTNAME=	gnome-themes
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of themes and icons for GNOME2

BUILD_DEPENDS=	gtk-engines2>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines2 \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	gtk-engines2>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines2

CONFLICTS=	clearlooks-metacity-0.*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack metacity gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
