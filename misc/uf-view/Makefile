# New ports collection makefile for:	uf-view
# Date created:        			5 December 1994
# Whom:				Jonathan McGee <mcgee@mcgee.student.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	uf-view
PORTVERSION=	1.6.1
CATEGORIES=	misc
MASTER_SITES=	http://hadess.net/files/

MAINTAINER=	mcgee@wam.umd.edu

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=      yes
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
