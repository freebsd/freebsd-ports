PORTNAME=	aribb24
DISTVERSION=	1.0.4
CATEGORIES=	multimedia

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	ARIB STD-B24 library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	jeeb
GH_TAGNAME=	a41b904
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
