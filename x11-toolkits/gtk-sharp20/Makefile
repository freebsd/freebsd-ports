# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-sharp

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS+=	mono:${PORTSDIR}/lang/mono \
		gst-launch:${PORTSDIR}/multimedia/gstreamer
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgda2 libgnomeui libgnomedb libgtkhtml

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/parser/Makefile.in

.include <bsd.port.mk>
