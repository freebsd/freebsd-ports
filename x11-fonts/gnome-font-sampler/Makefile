# New ports collection makefile for:	gnome-font-sampler
# Date created:			31 Dec 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		gnome-font-sampler
PORTVERSION=		0.4
PORTREVISION=	1
CATEGORIES=		x11-fonts
MASTER_SITES=		http://linuxadvocate.org/projects/gfontsampler/downloads/
DISTNAME=		gfontsampler-${PORTVERSION}

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A program for viewing several fonts at once

USE_X_PREFIX=		yes
USE_GCC=		3.4
USE_GNOME=		libgnomeui gnomeprefix
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		's|^packagedatadir=.*|packagedatadir=share/gnome| ; \
		 s|^packagepixmapsdir=.*|packagepixmapsdir=share/gnome/pixmaps| ; \
		 s|^packagemenudir=.*|packagemenudir=share/gnome/applications|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|\(@NO_PREFIX_PACKAGE_MENU_DIR@\)/Utilities|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
