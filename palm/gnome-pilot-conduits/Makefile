# New ports collection makefile for:	gnomepilot-conduits
# Date created:		16th March 2000
# Whom:			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot-conduits
PORTVERSION=	0.4
CATEGORIES=	palm comms gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-pilot-conduits
DISTNAME=	gnome-pilot-conduits-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link \
		gpilotd.0:${PORTSDIR}/palm/gnomepilot

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMECTRL=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure mal-conduit/configure
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/pilot/include" \
		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/pilot/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
