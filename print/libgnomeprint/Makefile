# New ports collection makefile for:	libgnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomeprint
PORTVERSION=	1.116.3
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.116
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	bonobo-2.0:${PORTSDIR}/devel/libbonobo \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name '*.[ch]' | xargs ${REINPLACE_CMD} -e \
		's|<malloc[.]h>|<stdlib.h>|'

post-install:
	@${MKDIR} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts
	@${TOUCH} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts/gnome-print.fontmap

.include <bsd.port.mk>
