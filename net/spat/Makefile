# New ports collection makefile for:	spat
# Date created:				31 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spat
PORTVERSION=	1.0
CATEGORIES=	net gnome
MASTER_SITES=	http://spat.codehost.com/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1$/-1/}.src

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1$//}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-lcompat -L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	${MKDIR} ${PREFIX}/share/gnome/apps/Applications \
		 ${PREFIX}/etc/CORBA/servers
.for file in spat.desktop spatd.desktop
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/gnome/apps/Applications
.endfor
	${INSTALL_DATA} ${WRKSRC}/spatd.gnorba ${PREFIX}/etc/CORBA/servers
	${LN} -sf ${PREFIX}/share/gnome/pixmaps/spat/spat.png \
		  ${PREFIX}/share/gnome/pixmaps/spat.png

.include <bsd.port.mk>
