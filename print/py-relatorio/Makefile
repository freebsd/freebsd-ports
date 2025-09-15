PORTNAME=	relatorio
PORTVERSION=	0.11.1
PORTREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Templating library able to output odt and pdf files
WWW=		https://docs.tryton.org/relatorio/latest/ \
		https://github.com/tryton/relatorio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:textproc/py-genshi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

OPTIONS_DEFINE=	CHART FODT
OPTIONS_DEFAULT=CHART FODT
CHART_DESC=	Chart support
FODT_DESC=	OpenDocument support

CHART_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycha>=0.4.0:graphics/py-pycha@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
FODT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-magic>=0:devel/py-python-magic@${PY_FLAVOR}

.include <bsd.port.mk>
