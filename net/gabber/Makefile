# New ports collection makefile for:	gabber
# Date created:				20 Jun 2000
# Whom:				Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=	gabber
PORTVERSION=	0.8.3
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomemm.9:${PORTSDIR}/x11-toolkits/gnome--

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure jabberoo/configure
CONFIGURE_ENV+=	GNOME_LIBCONFIG_PATH="${LOCALBASE}/lib:${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gabber.1

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@find ${WRKSRC}/src -name "*.[ch]" | xargs ${PERL} -pi -e \
		's|\<iconv.h\>|\<giconv.h\>|g'

.include <bsd.port.mk>
