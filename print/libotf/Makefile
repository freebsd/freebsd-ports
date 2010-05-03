# New ports collection makefile for:   libotf
# Date created:                18 May 2004
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	libotf
PORTVERSION=	0.9.11
CATEGORIES=	print devel
MASTER_SITES=	http://www.m17n.org/libotf/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Library for handling OpenType fonts

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_XORG=	x11 xt xaw xmu
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+= CPPFLAGS="-I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
