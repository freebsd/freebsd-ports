# New ports collection makefile for:	battstat_applet
# Date created:			17 July 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	battstat-applet
PORTVERSION=	2.0.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://spektr.eu.org/~jp/battstat/
DISTNAME=	battstat_applet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A laptop battery monitor utility for the GNOME panel

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix libpanel
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
