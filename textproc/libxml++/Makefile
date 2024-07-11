PORTNAME=	libxml++
DISTVERSION=	5.2.0
CATEGORIES=	textproc
MASTER_SITES=	GNOME \
		https://github.com/libxmlplusplus/libxmlplusplus/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	50

MAINTAINER=	jcfyecrayz@liamekaens.com
COMMENT=	XML API for C++
WWW=		https://github.com/libxmlplusplus/libxmlplusplus

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++17-lang gnome meson pkgconfig tar:xz
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=5.0 \
		API_VERSION=5.0

MESON_ARGS=	-Ddefault_library=both \
		-Dbuild-examples=false \
		-Dbuild-manual=false

.include <bsd.port.mk>
