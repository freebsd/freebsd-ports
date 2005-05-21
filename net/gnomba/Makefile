# New ports collection makefile for:	gnomba
# Date created:			10 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	gnomba
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnomba

MAINTAINER=	demon@FreeBSD.org
COMMENT=	GNOME compliant browser of SMB shares

BROKEN=		Incomplete pkg-plist

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gnomehier
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gnomba.1

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

pre-configure:
	${RM} ${WRKSRC}/config.cache

.include <bsd.port.mk>
