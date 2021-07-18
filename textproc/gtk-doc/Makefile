# Created by: fenner

PORTNAME=	gtk-doc
DISTVERSION=	1.33.2
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Code documentation system, originally for GTK+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		itstool:textproc/itstool \
		yelp-tools>=0:textproc/yelp-tools
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl

USES=		gettext-tools gnome meson python:3.6+ pkgconfig tar:xz
USE_GNOME=	libxml2 libxslt

MESON_ARGS=	-Dtests=false

NO_ARCH=	yes

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${DATADIR}/python/gtkdoc \
		${STAGEDIR}${DATADIR}/python/gtkdoc
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${DATADIR}/python/gtkdoc \
		${STAGEDIR}${DATADIR}/python/gtkdoc

.include <bsd.port.mk>
