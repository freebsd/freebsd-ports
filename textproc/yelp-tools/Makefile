PORTNAME=	yelp-tools
PORTVERSION=	42.0
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Utilities to help manage documentation for Yelp and the web
WWW=		https://wiki.gnome.org/Apps/Yelp/Tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		itstool:textproc/itstool \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt \
		yelp-xsl>=0:textproc/yelp-xsl
RUN_DEPENDS=	xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt

USES=		localbase meson pkgconfig python \
		shebangfix tar:xz
SHEBANG_FILES=	tools/yelp-build.in tools/yelp-check.in tools/yelp-new.in

BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
