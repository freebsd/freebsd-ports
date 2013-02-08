# $FreeBSD$

PORTNAME=	libxaw3dxft
DISTVERSION=	1.6.2b
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/sf-xpaint/${PORTNAME}
DISTNAME=	libXaw3dXft-${DISTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	3D Xaw (Athena Widget Set) replacement with extended fonts

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XORG=	xft xmu xpm

CONFIGURE_ARGS+=--enable-internationalization --enable-arrow-scrollbars
CPPFLAGS+=	-I${LOCALBASE}/include/freetype2

DOCSDIR=	${LOCALBASE}/share/doc/libXaw3dXft
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} '/^pkgconfigdir/s:=.*:= ${PREFIX}/libdata/pkgconfig:'\
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/^typedef.*Pixel;/d' ${WRKSRC}/src/Xaw3dXft.c

.include <bsd.port.mk>
