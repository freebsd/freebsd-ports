# New ports collection makefile for:	gnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeprint
PORTVERSION=	0.24
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-print
DISTNAME=	gnome-print-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

BUILD_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		xml.5:${PORTSDIR}/textproc/libxml \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

PLIST_SUB=	VERSION=${PORTVERSION}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
