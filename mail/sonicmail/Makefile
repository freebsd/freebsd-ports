# New ports collection makefile for:   sonicmail
# Date created:        13 September 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sonicmail
PORTVERSION=	0.1.2
CATEGORIES=	mail
MASTER_SITES=	http://download.sourceforge.net/sonicmail/

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOME=	yes

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
