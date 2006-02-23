# New ports collection makefile for:    eel2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/eel/Makefile,v 1.21 2005/10/03 15:22:10 ahze Exp $
#

PORTNAME=	eel
PORTVERSION=	2.12.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generally useful classes and extensions to GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack gail gnomedesktop gnomemenus ltverhack
USE_AUTOTOOLS=  libtool:15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/eel/eel-open-with-dialog.c

.include <bsd.port.mk>
