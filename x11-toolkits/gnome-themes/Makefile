# New ports collection makefile for:	gnome-themes
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-themes
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.4
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of themes and icons for GNOME 2 designed for accessibility

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-toolkits/gtk-engines2
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-toolkits/gtk-engines2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomehack metacity libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'

.include <bsd.port.mk>
