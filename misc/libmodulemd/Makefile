# $FreeBSD$

PORTNAME=	libmodulemd
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2.9.4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C Library for manipulating module metadata files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		help2man:misc/help2man
LIB_DEPENDS=	librpmio.so:archivers/rpm4 \
		libyaml.so:textproc/libyaml

USES=		gnome meson pkgconfig
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddeveloper_build=false -Dskip_formatters=true -Dwith_manpages="enabled" -Dwith_docs=false

USE_GITHUB=	yes
GH_ACCOUNT=	fedora-modularity

.include <bsd.port.mk>
