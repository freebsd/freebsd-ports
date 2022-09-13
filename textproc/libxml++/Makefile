PORTNAME=	libxml++
PORTVERSION=	5.0.2
CATEGORIES=	textproc
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}

MAINTAINER=	jcfyecrayz@liamekaens.com
COMMENT=	XML API for C++
WWW=		https://github.com/libxmlplusplus/libxmlplusplus

LICENSE=	LGPL21+

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddefault_library=both

PLIST_SUB=	VERSION=${PORTVERSION:R} API_VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
