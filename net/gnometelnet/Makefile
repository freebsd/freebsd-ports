# New ports collection makefile for:	gnometelnet
# Date created:		2 August 2000
# Whom:			Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnometelnet
PORTVERSION= 	2.0
CATEGORIES=	net gnome
MASTER_SITES=	http://cyest.hypermart.net/downloads/
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	${MKDIR} ${PREFIX}/share/gnome/apps/Internet
	${MKDIR} ${PREFIX}/share/gnome/pixmaps/gtelnet
	cd ${WRKSRC}/share && \
		${INSTALL_DATA} GTelnet.desktop ${PREFIX}/share/gnome/apps/Internet && \
		${INSTALL_DATA} *.jpg *.png ${PREFIX}/share/gnome/pixmaps/gtelnet

.include <bsd.port.mk>
