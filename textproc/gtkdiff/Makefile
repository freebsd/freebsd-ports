# New ports collection makefile for:	gtkdiff
# Date created:				17 November 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkdiff
PORTVERSION=	1.0.2
CATEGORIES=	textproc gnome
MASTER_SITES=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gtkdiff.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
