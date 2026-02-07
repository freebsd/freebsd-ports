PORTNAME=	libxml++
DISTVERSION=	3.2.5
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	30

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	XML API for C++
WWW=		https://libxmlplusplus.github.io/libxmlplusplus/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig tar:xz
USE_GNOME=	glibmm libxml2
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddefault_library=both

PLIST_SUB=	API_VERSION="3.0" \
		VERSION="3.0"

.include <bsd.port.mk>
