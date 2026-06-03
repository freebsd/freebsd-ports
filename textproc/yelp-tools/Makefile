PORTNAME=	yelp-tools
PORTVERSION=	42.1
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utilities to help manage documentation for Yelp and the web
WWW=		https://gitlab.gnome.org/GNOME/yelp-tools

LICENSE=	GPLv2+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		itstool:textproc/itstool \
		yelp-xsl>=0:textproc/yelp-xsl

USES=		gettext gnome localbase meson pathfix pkgconfig python \
		shebangfix tar:xz
USE_GNOME=	libxml2 libxslt
SHEBANG_FILES=	tools/yelp-build.in tools/yelp-check.in tools/yelp-new.in

BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

.include <bsd.port.mk>
