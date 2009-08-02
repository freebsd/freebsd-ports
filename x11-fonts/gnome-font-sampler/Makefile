# New ports collection makefile for:	gnome-font-sampler
# Date created:			31 Dec 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gnome-font-sampler
PORTVERSION=	0.4
PORTREVISION=	9
CATEGORIES=	x11-fonts
MASTER_SITES=	http://linuxadvocate.org/projects/gfontsampler/downloads/
DISTNAME=	gfontsampler-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program for viewing several fonts at once

USE_XORG=	x11
USE_GNOME=	libgnomeui gnomeprefix
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		's|^packagedatadir=.*|packagedatadir=share| ; \
		 s|^packagepixmapsdir=.*|packagepixmapsdir=share/pixmaps| ; \
		 s|^packagemenudir=.*|packagemenudir=share/applications|; \
		 /^CFLAGS=""$$/ d; s|gtk+-2.0|pangoxft &|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|\(@NO_PREFIX_PACKAGE_MENU_DIR@\)/Utilities|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
