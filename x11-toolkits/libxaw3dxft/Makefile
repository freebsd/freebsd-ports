# $FreeBSD$

PORTNAME=	libxaw3dxft
DISTVERSION=	1.6.2d
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/sf-xpaint/${PORTNAME}
DISTNAME=	libXaw3dXft-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Xaw (Athena Widget Set) replacement with extended fonts

LIB_DEPENDS=	libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_XORG=	xft xmu xpm

INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--enable-internationalization --enable-arrow-scrollbars
CPPFLAGS+=	-I${LOCALBASE}/include/freetype2

DOCSDIR=	${LOCALBASE}/share/doc/libXaw3dXft
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} '/^typedef.*Pixel;/d' ${WRKSRC}/src/Xaw3dXft.c

.include <bsd.port.mk>
