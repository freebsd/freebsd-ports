# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	pdfarranger
DISTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	print

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Split, Merge, Rotate and Reorder PDF Files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pikepdf>0:textproc/py-pikepdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		poppler-glib>0:graphics/poppler-glib

USES=		python gnome gettext
USE_PYTHON=	distutils
USE_GNOME=	intltool:build gtk30
USE_GITHUB=	yes

NO_ARCH=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
