# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION=	1.1.3
#PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		pspell.4:${PORTSDIR}/textproc/pspell \
		gnomeprint.13:${PORTSDIR}/print/gnomeprint \
		giconv.2:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ARGS=	--enable-threads \
		--disable-more-warnings
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgiconv"

MAN1=		balsa.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|-liconv|-lgiconv|g ; s|iconv_open|libiconv_open|g' \
			${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(gnomedatadir\)/gnome|\$\(gnomedatadir\)|g'

.include <bsd.port.mk>
