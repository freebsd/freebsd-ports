# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.screem.org/src/ \
		http://www.borgsdemons.com/distfiles/screem/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-docs${EXTRACT_SUFX}

MAINTAINER=	jmcoopr@webmail.bmi.net

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gnomevfs --with-ssl --with-included-neon

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\@GNOME_DATA_PREFIX\@|\$$\(datadir\)|g ; \
		 s|\$\(datadir\)/gnome|\$\(datadir\)|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	@${INSTALL_DATA} ${WRKSRC}/../${PORTNAME}-docs/* \
		${PREFIX}/share/gnome/help/screem/C/

.include <bsd.port.mk>
