# New ports collection makefile for:	gnomepilot-conduits
# Date created:		16th March 2000
# Whom:			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot-conduits
PORTVERSION=	0.8
CATEGORIES=	palm comms gnome
MASTER_SITES=	http://www.eskil.org/gnome-pilot/download/tarballs/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-pilot-conduits
DISTNAME=	gnome-pilot-conduits-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gpilotd.1:${PORTSDIR}/palm/gnomepilot

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMECTRL=	yes
USE_LIBTOOL=	yes
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
