# New ports collection makefile for:	gnomepilot
# Date created:		28th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot
PORTVERSION=	0.1.69
CATEGORIES=	palm comms gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://www.eskil.org/gnome-pilot/download/tarballs/
MASTER_SITE_SUBDIR=	sources/gnome-pilot/0.1
DISTNAME=	gnome-pilot-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	gob:${PORTSDIR}/x11-toolkits/gob
LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs libglade gnomevfs libpanel \
		libcapplet
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gpilot-install-file.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
