# New ports collection makefile for:	gnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeprint
PORTVERSION=	0.37
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-print/0.37
DISTNAME=	gnome-print-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

PLIST_SUB=	VERSION=${PORTVERSION}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier gnomelibs gnomecanvas
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	@${TOUCH} ${PREFIX}/etc/gnome/fonts/gnome-print-x11.fontmap

.include <bsd.port.mk>
