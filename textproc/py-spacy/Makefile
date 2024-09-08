PORTNAME=	spacy
PORTVERSION=	3.7.6
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Industrial-strength Natural Language Processing (NLP) in Python
WWW=		https://spacy.io/ \
		https://github.com/explosion/spaCy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cymem>=2.0.2<2.1.0:devel/py-cymem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}murmurhash>=0.28.0<1.1.0:devel/py-murmurhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}preshed3>=3.0.2<3.1.0:devel/py-preshed3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thinc8>=8.2.2<8.3.0_99:devel/py-thinc8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}catalogue>=2.0.6<2.1.0:devel/py-catalogue@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cymem>=2.0.2<2.1.0:devel/py-cymem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langcodes>=3.2.0<4.0.0:textproc/py-langcodes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}murmurhash>=0.28.0<1.1.0:devel/py-murmurhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.19.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}preshed3>=3.0.2<3.1.0:devel/py-preshed3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.7.4<3.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13.0<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spacy-legacy>=3.0.11<3.1.0:textproc/py-spacy-legacy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spacy-loggers>=1.0.0<2.0.0:textproc/py-spacy-loggers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}srsly>=2.4.3<3.0.0:devel/py-srsly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thinc8>=8.2.2<8.3.0_99:devel/py-thinc8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.38.0<5.0.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.3.0<1.0.0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wasabi>=0.9.1<1.2.0:textproc/py-wasabi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}weasel>=0.1.0<0.5.0:devel/py-weasel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
