PORTNAME=	instructor
DISTVERSION=	1.8.2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Structured outputs for llms
WWW=		https://python.useinstructor.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openai>=1.52.0<2.0.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.8.0<3.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.16<1.0:textproc/py-docstring_parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.9.0<1.0.0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9.1<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.0.0<10.0.0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-core>=2.18.0<3.0.0:devel/py-pydantic-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jiter>=0.6.1:textproc/py-jiter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.4<4.0.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
