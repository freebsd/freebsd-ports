# Ports collection Makefile for:	encompass
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	encompass
PORTVERSION=	0.3.3
CATEGORIES=	www gnome
MASTER_SITES=	http://dobey.free.fr/encompass/ \
		http://zephyr.webhop.net/encompass/ \
		ftp://ftp.one.net/pub/users/dobez/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkhtml.8:${PORTSDIR}/www/gtkhtml \
		glibwww.1:${PORTSDIR}/www/glibwww \
		gconf-1.1:${PORTSDIR}/devel/gconf \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		gnomeprint.13:${PORTSDIR}/print/gnomeprint
RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/login.wav:${PORTSDIR}/audio/gnomeaudio

USE_GNOME=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
