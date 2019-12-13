# $FreeBSD$

PORTNAME=	libwpe
PORTVERSION=	1.4.0.1
CATEGORIES=	www
MASTER_SITES=	https://wpewebkit.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	General-purpose library for WPE WebKit

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c11 gl localbase:ldflags pkgconfig \
		tar:xz

USE_GL=		egl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
