# New ports collection makefile for:	control-center
# Date created:				29 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-control-center1/Makefile,v 1.3 2007/05/30 05:02:04 mezz Exp $
#

PORTNAME=	gnome-control-center
PORTVERSION=	1.4.0.5
PORTREVISION=	12
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/control-center/1.4
DISTNAME=	control-center-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME project

USE_BZIP2=	yes
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomecanvas gnomevfs libcapplet
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

LATEST_LINK=	gnome-control-center1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/capplets/wm-properties/wm-desktops/WindowMaker.desktop

.include <bsd.port.mk>
