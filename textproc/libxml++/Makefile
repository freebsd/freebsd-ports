PORTNAME=	libxml++
DISTVERSION=	5.4.0
PORTREVISION=	2
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

MESON_ARGS=	-Dbuild-examples=false \
		-Dbuild-manual=false \
		-Ddefault_library=both

PLIST_SUB=	API_VERSION=5.0 \
		VERSION=5.0

.include <bsd.port.mk>
