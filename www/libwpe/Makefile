PORTNAME=	libwpe
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://wpewebkit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	General-purpose library for WPE WebKit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gl meson pkgconfig tar:xz
USE_GL=		egl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
