# New ports collection makefile for:	metatheme
# Date created:				25 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metatheme
PORTVERSION=	0.5.0
CATEGORIES=	misc gnome
MASTER_SITES=	ftp://ftp.helixcode.com/pub/metatheme/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkhtml.8:${PORTSDIR}/www/gtkhtml \
		gal.4:${PORTSDIR}/x11-toolkits/gal \
		gnet.0:${PORTSDIR}/net/gnet

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-configure:
.for file in gtk/gtk-plugin.c background/background-plugin.c sawfish/sawfish-plugin.c
	@${PERL} -pi -e 's|%%GTK_CONFIG%%|${GTK_CONFIG}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/plugins/${file}
.endfor

.include <bsd.port.mk>
