# New ports collection makefile for:   at-spi
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	at-spi
PORTVERSION=	1.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-rc1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gailutil.16:${PORTSDIR}/x11-toolkits/gail \
		bonobo-2.0:${PORTSDIR}/devel/libbonobo

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc \
		--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g ; \
		 s|\$\(libdir\)/bonobo/servers|\$\(prefix\)/libdata/bonobo/servers|g'

.include <bsd.port.mk>
