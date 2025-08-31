PORTNAME=	pdfarranger
DISTVERSION=	1.10.1
PORTREVISION=	4
CATEGORIES=	print
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Split, Merge, Rotate and Reorder PDF Files
WWW=		https://github.com/pdfarranger/pdfarranger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pikepdf>0:textproc/py-pikepdf@${PY_FLAVOR} \
		poppler-glib>0:graphics/poppler-glib

USES=		gettext gnome python
USE_GITHUB=	yes
USE_GNOME=	gtk30 intltool:build pygobject3:run
USE_PYTHON=	distutils

NO_ARCH=	yes

.include <bsd.port.mk>
