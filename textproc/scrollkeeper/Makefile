# New ports collection makefile for:	scrollkeeper
# Date created:				6 April 2001
# Whom:					Rene Hexel <rh@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	scrollkeeper
PORTVERSION=	0.3.6
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-beta5
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	xslt.1:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/share/xml/docbook/4.1.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml

# Don't use USE_X_PREFIX - the port doesn't really require X11 to run.
# The reason why it should be in X11BASE is that GNOME is the primary
# (only?) consumer of this port, and BadThings[tm] happen if it's not
# put in the right place.
PREFIX?=	${X11BASE}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=/var --datadir=${PREFIX}/share/gnome \
		--with-omfdirs=${PREFIX}/share/gnome/omf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl" \
		LOCALBASE="${LOCALBASE}"

MAN1=	scrollkeeper-config.1 scrollkeeper-gen-seriesid.1
MAN5=	scrollkeeper.conf.5
MAN7=	scrollkeeper.7
MAN8=	scrollkeeper-preinstall.8 scrollkeeper-rebuilddb.8 \
	scrollkeeper-update.8

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e   \
		's|\$$\(LN_S\) -f -n|\$$\(LN_S\) -f|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g ; \
		 s|\$\(libdir\)/bonobo/servers|\$\(prefix\)/libdata/bonobo/servers|g'
	@${PERL} -pi -e 's|/usr/share/locale|${PREFIX}/share/locale|g' \
		${WRKSRC}/libs/scrollkeeper.h.in

post-patch:
	@${PERL} -pi -e 's|\%\%PREFIX\%\%|${PREFIX}|g' \
		${WRKSRC}/cl/src/update.c
	@${PERL} -pi -e 's|\%\%DATADIR\%\%|${PREFIX}/share/gnome|g' \
		${WRKSRC}/config/scrollkeeper.conf

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/scrollkeeper/TOC

.include <bsd.port.mk>
