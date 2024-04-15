PORTNAME=	gtk-doc
DISTVERSION=	1.33.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Code documentation system, originally for GTK
WWW=		https://www.gtk.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		itstool:textproc/itstool \
		yelp-tools>=0:textproc/yelp-tools \
		xsltproc:textproc/libxslt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		xsltproc:textproc/libxslt

USES=		gettext-tools meson python pkgconfig tar:xz

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
