# New ports collection makefile for:	gnomepilot
# Date created:		28th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot
PORTVERSION=	0.1.64
CATEGORIES=	palm comms gnome
MASTER_SITES=	http://www.eskil.org/gnome-pilot/download/tarballs/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-pilot
DISTNAME=	gnome-pilot-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	gob:${PORTSDIR}/x11-toolkits/gob \
		${LOCALBASE}/pilot/lib/libpisock.a:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS=	${LOCALBASE}/pilot/lib/libpisock.a:${PORTSDIR}/palm/pilot-link

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
