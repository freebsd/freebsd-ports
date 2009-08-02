# New ports collection makefile for:	gal
# Date created:				5th October 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gal
PORTVERSION=	0.24
PORTREVISION=	7
CATEGORIES?=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	A collection of widgets taken from GNOME gnumeric and evolution

LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode

USE_BZIP2=	yes
USE_XORG=	x11
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier libglade gnomevfs
USE_ICONV=	yes
USE_GETTEXT=	yes
GNOME_HTML_DIR=	${PREFIX}/share/doc/gal
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--enable-static --with-libiconv
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
