# New ports collection makefile for:    eel2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/eel/Makefile,v 1.51 2007/03/12 15:59:00 ahze Exp $
#

PORTNAME=	eel
PORTVERSION=	2.18.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generally useful classes and extensions to GNOME

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack gail gnomedesktop gnomemenus ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/eel/eel-open-with-dialog.c

.include <bsd.port.mk>
