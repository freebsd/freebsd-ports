# New ports collection makefile for:   libgail-gnome
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgail-gnome
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-beta3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		spi.0:${PORTSDIR}/x11-toolkits/at-spi

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome2 \
		--datadir=${PREFIX}/share/gnome2 \
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
