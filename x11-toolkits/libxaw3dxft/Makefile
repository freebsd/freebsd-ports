PORTNAME=	libxaw3dxft
DISTVERSION=	1.6.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://github.com/DaveFlater/libXaw3dXft/releases/download/v${DISTVERSION}/

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	3D Xaw (Athena Widget Set) replacement with extended fonts
WWW=		https://github.com/DaveFlater/libXaw3dXft/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pkgconfig tar:xz xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xmu xpm xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-arrow-scrollbars \
		--enable-internationalization
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
