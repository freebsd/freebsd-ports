PORTNAME=	textual-fastdatatable
DISTVERSION=	0.14.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Reimplementation of Textual's DataTable widget
WWW=		https://github.com/tconbeer/textual-fastdatatable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.28.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.3.3,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=21.0.0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual>=0.89.1:textproc/py-textual@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2025.3:devel/py-tzdata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		DATAFRAME
DATAFRAME_DESC=		Enable DataFrame interface via misc/py-polars
DATAFRAME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}polars>=1.36.1:misc/py-polars

.include <bsd.port.mk>
