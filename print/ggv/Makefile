# New ports collection makefile for:	ggv2
# Date created:				07 July 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/print/ggv/Makefile,v 1.8 2007/09/24 19:40:45 mezz Exp $
#

PORTNAME=	ggv
PORTVERSION=	2.12.0
PORTREVISION=	8
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 ghostscript viewer

USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui desktopfileutils
USE_GETTEXT=	yes
USE_GHOSTSCRIPT=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	ggv.schemas

post-install:
	@-update-desktop-database > /dev/null

.include <bsd.port.mk>
