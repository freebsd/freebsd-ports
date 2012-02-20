# New ports collection makefile for:	libxaw3dxft
# Date created:		18 Feb 2012
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	libxaw3dxft
PORTVERSION=	1.3.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/sf-xpaint/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	3D Xaw (Athena Widget Set) replacement with extended fonts

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XORG=	xft xmu xpm

CPPFLAGS+=	-I${LOCALBASE}/include/freetype2

post-patch:
	@${REINPLACE_CMD} 's:/usr/lib/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
