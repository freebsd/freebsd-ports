# New ports collection makefile for:	glitter
# Date Created:		09 Dec 2000
# Whom:			Greg Greenaae <greg@gregnet.net>
#
# $FreeBSD$
#

PORTNAME=	glitter
PORTVERSION=	1.0.b.1
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://mews.org.uk/glitter/\
		ftp://ftp.gregnet.net/pub/FreeBSD/ports/news/glitter/
DISTNAME=	${PORTNAME}-1.0beta1

MAINTAINER=	greg@gregnet.net

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gtk12
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
