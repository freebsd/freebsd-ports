# New ports collection makefile for:	netspeed_applet
# Date created:				08 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netspeed_applet
PORTVERSION=	0.8
CATEGORIES=	net gnome
MASTER_SITES=	http://mfcn.ilo.de/netspeed_applet/

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	panel-applet-2.0:${PORTSDIR}/x11/gnomepanel \
		gtop-2.0:${PORTSDIR}/devel/libgtop2

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehier gnomeprefix gnomehack
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
