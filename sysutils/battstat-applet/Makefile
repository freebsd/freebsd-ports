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

BROKEN=		"Does not install"

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
