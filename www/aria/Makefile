# New ports collection makefile for:   aria
# Date created:        30 March 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria
PORTVERSION=	0.9.1.1
CATEGORIES=	www
MASTER_SITES=	http://aria.rednoah.com/storage/sources/
DISTNAME=	${PORTNAME}-0.9.1pl1

MAINTAINER=	nakai@FreeBSD.org

USE_BZIP2=	yes
USE_GTK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=    yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		 's|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
