PORTNAME=	libsecret
PORTVERSION=	0.21.7
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API
WWW=		https://gitlab.gnome.org/GNOME/libsecret

LICENSE=	APACHE20 GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR} \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		compiler gettext gnome meson pkgconfig python tar:xz vala:build
USE_GNOME=	glib20 introspection:build libxslt:build

MESON_ARGS=	-Dbash_completion=disabled

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-incompatible-function-pointer-types
.endif

.include <bsd.port.post.mk>
