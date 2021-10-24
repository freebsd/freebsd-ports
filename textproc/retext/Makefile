PORTNAME=	retext
DISTVERSION=	7.2.2
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Markdown editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=2.0.3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Markups>=3.0.0:textproc/py-markups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-markdown-math>=0.6:textproc/py-python-markdown-math@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${PY_FLAVOR}

USES=		python:3.2+ desktop-file-utils pyqt:5 qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	retext-project
GH_PROJECT=	retext
USE_PYTHON=	distutils autoplist noflavors
USE_QT=		linguisttools_build
USE_PYQT=	pyqt5_run sip_run

BINARY_ALIAS=	lrelease=${LRELEASE}

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e "s,lrelease,${LRELEASE}," ${WRKSRC}/setup.py

.include <bsd.port.mk>
