# New ports collection makefile for:    nautilus2
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#

PORTNAME=	nautilus2
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.4
DIST_SUBDIR=	gnome2
DISTNAME=	nautilus-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME file manager and graphical shell developed by Eazel

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier gnomedesktop eel2 \
		librsvg2
GNOME_DESKTOP_VERSION=2
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz ${MOZILLA_LIBS}"
CONFIGURE_ARGS=	--with-freetype2-lib-place=${LOCALBASE}/lib \
		--with-freetype2-include-place=${LOCALBASE}/include/freetype2 \
		--enable-static
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

post-install:
	@${CHMOD} u+w ${PREFIX}/share/gnome/nautilus/*.desktop

.include <bsd.port.mk>
