# New ports collection makefile for:	gnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeprint
PORTVERSION=	0.25
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-print
DISTNAME=	gnome-print-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6
LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

PLIST_SUB=	VERSION=${PORTVERSION}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GNOMELIBS=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
