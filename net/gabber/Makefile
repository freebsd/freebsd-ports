# New ports collection makefile for:	gabber
# Date created:				20 Jun 2000
# Whom:				Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=	gabber
PORTVERSION=	0.8.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erich@tacni.net

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		gnomemm.3:${PORTSDIR}/x11-toolkits/gnome-- \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		gal.4:${PORTSDIR}/x11-toolkits/gal \
		giconv.2:${PORTSDIR}/converters/libiconv \
		glade.4:${PORTSDIR}/devel/libglade

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure jabberoo/configure
CONFIGURE_ENV+=	GNOME_LIBCONFIG_PATH="${LOCALBASE}/lib:${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
