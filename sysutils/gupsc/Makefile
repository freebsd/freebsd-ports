# New ports collection makefile for:	gupsc
# Date created:				13 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupsc
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://heim.ifi.uio.no/~hennikul/gupsc/download/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A free Gnome client for the Network UPS Tools

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure \
		${WRKSRC}/src/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
