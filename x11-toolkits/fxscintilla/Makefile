PORTNAME=	fxscintilla
PORTVERSION=	2.28.0
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fox toolkit reimplementation of Scintilla editing widget
WWW=		https://www.nongnu.org/fxscintilla/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16

USES=		libtool pathfix pkgconfig
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
