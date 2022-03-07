# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	pdfarranger
DISTVERSION=	1.8.2
CATEGORIES=	print

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Split, Merge, Rotate and Reorder PDF Files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pikepdf>0:textproc/py-pikepdf@${PY_FLAVOR} \
		poppler-glib>0:graphics/poppler-glib

USES=		gettext gnome python
USE_PYTHON=	distutils
USE_GNOME=	gtk30 intltool:build
USE_GITHUB=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
