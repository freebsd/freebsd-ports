# New ports collection makefile for:   linc
# Date Created:			12 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linc
PORTVERSION=	0.1.16
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-alpha2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-1.3.13:${PORTSDIR}/devel/glib13
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'

.include <bsd.port.mk>
