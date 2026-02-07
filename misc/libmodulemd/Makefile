PORTNAME=	libmodulemd
DISTVERSION=	2.15.2
CATEGORIES=	misc
MASTER_SITES=	https://github.com/fedora-modularity/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	modulemd-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C Library for manipulating module metadata files
WWW=		https://github.com/fedora-modularity/libmodulemd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		help2man:misc/help2man
LIB_DEPENDS=	librpmio.so:archivers/rpm4 \
		libyaml.so:textproc/libyaml
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gnome meson pkgconfig shebangfix tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

SHEBANG_FILES=	modulemd/tests/test-import-headers.sh

MESON_ARGS=	-Dwith_manpages="enabled" -Dwith_docs=false

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

# tests as of 2.15.2:
# Ok:                 115
# Expected Fail:      0
# Fail:               0
# Unexpected Pass:    0
# Skipped:            0
# Timeout:            0

.include <bsd.port.mk>
