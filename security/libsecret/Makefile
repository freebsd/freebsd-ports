PORTNAME=	libsecret
PORTVERSION=	0.20.5
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR} \
		docbook-xsl>=0:textproc/docbook-xsl \
		vala:lang/vala
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		gnome meson pkgconfig python:3.8+ tar:xz
USE_GNOME=	glib20 intltool introspection:build libxslt:build

.include <bsd.port.mk>
