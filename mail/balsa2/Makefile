# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION= 	1.0.pre1
#PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		pspell.2:${PORTSDIR}/textproc/pspell \
		gnomeprint.12:${PORTSDIR}/print/gnomeprint

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ARGS=	--enable-threads \
		--disable-more-warnings
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		balsa.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(gnomedatadir\)/gnome|\$\(gnomedatadir\)|g'
	@find ${WRKSRC}/help -name "*.html" | xargs ${PERL} -pi -e \
		's|\.gif|.png|g'

.include <bsd.port.mk>
