# New ports collection makefile for:	gnomepilot
# Date created:		28th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot
PORTVERSION=	0.1.52
CATEGORIES=	palm comms gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-pilot
DISTNAME=	gnome-pilot-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

BUILD_DEPENDS=	gob:${PORTSDIR}/x11-toolkits/gob
LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link \
		xml.5:${PORTSDIR}/textproc/libxml \
		glade.4:${PORTSDIR}/devel/libglade

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}/pilot
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/pilot/include" \
		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/pilot/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
