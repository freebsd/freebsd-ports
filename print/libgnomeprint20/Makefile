# New ports collection makefile for:	libgnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomeprint
PORTVERSION=	1.116.3
PORTREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.116
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

LATEST_LINK=	libgnomeprint20
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libbonobo libartlgpl2 gtk20
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc[.]h>|<stdlib.h>|'

post-install:
	@${MKDIR} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts
	@${TOUCH} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts/gnome-print.fontmap

.include <bsd.port.mk>
