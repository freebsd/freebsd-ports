PORTNAME=	libxml++
DISTVERSION=	2.42.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	GNOME \
		https://github.com/libxmlplusplus/libxmlplusplus/releases/download/${DISTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	XML API for C++
WWW=		https://libxmlplusplus.github.io/libxmlplusplus/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang meson gnome pkgconfig tar:xz
USE_GNOME=	glibmm libxml2
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="2.6" \
		API_VERSION="2.6"

MESON_ARGS=	-Ddefault_library=both \
		-Dbuild-examples=false \
		-Dbuild-manual=false

.include <bsd.port.mk>
