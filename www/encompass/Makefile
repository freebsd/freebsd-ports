# Ports collection Makefile for:	encompass
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	encompass
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	http://dobey.free.fr/encompass/ \
		http://zephyr.webhop.net/encompass/ \
		ftp://ftp.one.net/pub/users/dobez/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkhtml.10:${PORTSDIR}/www/gtkhtml

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
