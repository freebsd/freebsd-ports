# New ports collection makefile for:	COnfigurator for Gnome
# Date created:				01 May 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cog
PORTVERSION=	0.7.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.krakoa.dk/progs/cog/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program for editing advanced GNOME settings in an easy way

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|Icon=|Icon=cog-icon-2-48x48.png|g' \
		${WRKSRC}/cog.desktop

post-install:
	@${LN} -sf ${PREFIX}/share/gnome/cog/pixmaps/cog-icon-2-48x48.png \
		${PREFIX}/share/gnome/pixmaps/cog-icon-2-48x48.png

.include <bsd.port.mk>
