# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	yelp-tools
PORTVERSION=	42.0
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utilities to help manage documentation for Yelp and the web

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		itstool:textproc/itstool \
		yelp-xsl>=0:textproc/yelp-xsl

USES=		gettext gnome localbase meson pathfix pkgconfig python:3.7+ \
		shebangfix tar:xz
USE_GNOME=	libxml2 libxslt
SHEBANG_FILES=	tools/yelp-build.in tools/yelp-check.in tools/yelp-new.in

BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
