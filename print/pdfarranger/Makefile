PORTNAME=	pdfarranger
DISTVERSION=	1.14.0
CATEGORIES=	print
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avereeken@fastmail.de
COMMENT=	Split, Merge, Rotate and Reorder PDF Files
WWW=		https://github.com/pdfarranger/pdfarranger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pikepdf>0:textproc/py-pikepdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		poppler-glib>0:graphics/poppler-glib

USES=		desktop-file-utils gettext-tools gnome python
USE_GITHUB=	yes
USE_PYTHON=	pep517

NO_ARCH=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
