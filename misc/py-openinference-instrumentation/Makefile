PORTNAME=	openinference-instrumentation
PORTVERSION=	0.1.63
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenInference: Iinstrumentation utilities
WWW=		https://github.com/Arize-ai/openinference/tree/main/python/openinference-instrumentation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openinference-semantic-conventions>=0.1.37:misc/py-openinference-semantic-conventions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.14.0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
