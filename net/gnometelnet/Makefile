# New ports collection makefile for:	gnometelnet
# Date created:				2 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnometelnet
PORTVERSION=	2.4
CATEGORIES=	net gnome
MASTER_SITES=	http://www.cyest.org/downloads/
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

pre-configure:
.for file in install-sh mkinstalldirs
	${LN} -sf ${LOCALBASE}/share/automake/${file} ${WRKSRC}/${file}
.endfor
	${RM} -f ${WRKSRC}/config.cache

post-install:
	${MKDIR} ${PREFIX}/share/gnome/apps/Internet
	${MKDIR} ${PREFIX}/share/gnome/pixmaps/gnome-telnet
	cd ${WRKSRC}/share && \
		${INSTALL_DATA} GTelnet.desktop ${PREFIX}/share/gnome/apps/Internet && \
		${INSTALL_DATA} *.jpg *.png ${PREFIX}/share/gnome/pixmaps/gnome-telnet
	${LN} -sf ${PREFIX}/share/gnome/pixmaps/gnome-telnet/gnome-telnet.png \
		${PREFIX}/share/gnome/pixmaps/gnome-telnet.png

.include <bsd.port.mk>
