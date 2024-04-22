PORTNAME=	libsecret
PORTVERSION=	0.20.5
PORTREVISION=	3
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API
WWW=		https://wiki.gnome.org/Projects/Libsecret/

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR} \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR}

USES=		compiler gnome meson pkgconfig python tar:xz vala:build
USE_GNOME=	glib20 intltool introspection:build libxslt:build

TESTING_UNSAFE=	gi.repository.GLib.GError: g-io-error-quark: Remote closed the output

pre-test:
	@${MKDIR} ${BINARY_LINKDIR}
	@${LN} -s ${PYTHON_CMD} ${BINARY_LINKDIR}/python3

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-incompatible-function-pointer-types
.endif

.include <bsd.port.post.mk>
