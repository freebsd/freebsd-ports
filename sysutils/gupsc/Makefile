# New ports collection makefile for:	gupsc
# Date created:				13 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupsc
PORTVERSION=	0.3.1
PORTREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://heim.ifi.uio.no/~hennikul/gupsc/download/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A free Gnome client for the Network UPS Tools

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs gnomehier
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|/usr/local|${PREFIX}|; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
