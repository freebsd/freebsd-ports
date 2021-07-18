PORTNAME=	libmodulemd
DISTVERSION=	2.12.1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/fedora-modularity/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	modulemd-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C Library for manipulating module metadata files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		help2man:misc/help2man
LIB_DEPENDS=	librpmio.so:archivers/rpm4 \
		libyaml.so:textproc/libyaml

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddeveloper_build=false -Dskip_formatters=true -Dwith_manpages="enabled" -Dwith_docs=false

.include <bsd.port.mk>
