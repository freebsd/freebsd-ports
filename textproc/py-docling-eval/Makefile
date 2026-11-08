PORTNAME=	docling-eval
DISTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluation of Docling
WWW=		https://github.com/docling-project/docling-eval

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apted>=1.0.3:math/py-apted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.12.3:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}datasets>=3.2.0:misc/py-datasets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distance>=0.1.3:math/py-distance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling>=2.56.1:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-core>=2.48.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}edit-distance>=1.0.6:math/py-edit-distance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}editdistance>0:devel/py-editdistance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}evaluate>=0.4.3:misc/py-evaluate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jiwer>=3.1.0:misc/py-jiwer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=5.3.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.10.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.9.1:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.3:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=20.0.0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycocotools>=2.0.8:devel/py-pycocotools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf2>=3.0.1:graphics/py-pypdf2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=4.4.3:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.15.3:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy-stubs>=1.15.3.0:science/py-scipy-stubs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9.0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.5.1:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchmetrics>=1.6.0:misc/py-torchmetrics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.16.0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.14.2:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
