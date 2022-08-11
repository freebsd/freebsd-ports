PORTNAME=	libxml++
PORTVERSION=	5.0.1
CATEGORIES=	textproc
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}

MAINTAINER=	jcfyecrayz@liamekaens.com
COMMENT=	XML API for C++

LICENSE=	LGPL21+

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddefault_library=both

PLIST_SUB=	VERSION=${PORTVERSION:R} API_VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
