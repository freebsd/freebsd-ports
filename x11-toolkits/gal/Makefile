# New ports collection makefile for:	gal
# Date created:				5th October 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gal
PORTVERSION=	0.19
CATEGORIES?=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gal

MAINTAINER?=	gnome@FreeBSD.org

LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode \
		glade.4:${PORTSDIR}/devel/libglade \
		giconv.2:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMECTRL=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@find ${WRKSRC}/gal/widgets -name '*.[ch]' | xargs ${PERL} -pi -e \
		's|<iconv.h>|<giconv.h>|'

.include <bsd.port.mk>
