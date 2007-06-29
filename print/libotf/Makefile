# New ports collection makefile for:   libotf
# Date created:                18 May 2004
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	libotf
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	print devel
MASTER_SITES=	http://www.m17n.org/libotf/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Library for handling OpenType fonts

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_GNOME=	pkgconfig
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
