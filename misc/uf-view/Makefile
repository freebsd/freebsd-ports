# New ports collection makefile for:	uf-view
# Date created:        			30 May 2001
# Whom:				Jonathan McGee <mcgee@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	uf-view
PORTVERSION=	2.0
CATEGORIES=	misc
MASTER_SITES=	http://www.hadess.net/files/software/uf-view/

MAINTAINER=	mcgee@wam.umd.edu

LIB_DEPENDS=    gnomevfs-2.0:${PORTSDIR}/devel/gnomevfs2 \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		gnome-desktop-2.0:${PORTSDIR}/x11/gnomedesktop

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=    yes
USE_GNOME=      gnomeprefix gnomehack gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=       --target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
