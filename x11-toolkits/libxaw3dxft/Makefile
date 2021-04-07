PORTNAME=	libxaw3dxft
DISTVERSION=	1.6.2e
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/sf-xpaint/${PORTNAME}
DISTNAME=	libXaw3dXft-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Xaw (Athena Widget Set) replacement with extended fonts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		libtool pathfix pkgconfig tar:bzip2 xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xft xmu xpm xt
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--enable-internationalization --enable-arrow-scrollbars
CPPFLAGS+=	-I${LOCALBASE}/include/freetype2

DOCSDIR=	${LOCALBASE}/share/doc/libXaw3dXft
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/^typedef.*Pixel;/d' ${WRKSRC}/src/Xaw3dXft.c

.include <bsd.port.mk>
