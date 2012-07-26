# New ports collection makefile for:    gnomephotoprinter
# Date created:         27 Oct 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomephotoprinter
PORTVERSION=	0.7.0
PORTREVISION=	9
CATEGORIES=	print gnome
MASTER_SITES=	http://www.fogman.de/gpp/
DISTNAME=	gpp-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome Photo Printer is intended for printing photos in an easy way

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui libglade2 libgnomeprintui \
		gnomevfs2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -s "s/PKGCONFIG --version/PKGCONFIG --modversion pkg-config/g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
