# $FreeBSD$

PORTNAME=	retext
DISTVERSION=	7.0.4
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Markdown editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=2.0.3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Markups>=3.0.0:textproc/py-markups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-math>=0.6:textproc/py-markdown-math@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR}

USES=		python:3.2+ desktop-file-utils pyqt:5 qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	retext-project
GH_PROJECT=	retext
USE_PYTHON=	distutils autoplist noflavors
USE_QT=		linguisttools_build
USE_PYQT=	core_run sip_run gui_run widgets_run printsupport_run \
		network_run

PYDISTUTILS_INSTALLARGS+=	--no-rename

BINARY_ALIAS=	lrelease=${LRELEASE}

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e "s,lrelease,${LOCALBASE}/bin/lrelease," ${WRKSRC}/setup.py

.include <bsd.port.mk>
