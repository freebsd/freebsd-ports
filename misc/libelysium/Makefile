# Ports collection Makefile for:	libelysium
# Date created:				10 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libelysium
PORTVERSION=	0.3.5
CATEGORIES=	misc gnome
MASTER_SITES=	http://elysium.zoned.net/${PORTNAME}/

MAINTAINER=	sobomax@FreeBSD.org

USE_GNOMENG=	yes
USE_GNOME=	glib12
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
