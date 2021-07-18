# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	relatorio
PORTVERSION=	0.9.3
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Templating library able to output odt and pdf files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:textproc/py-genshi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}magic>=0:devel/py-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycha>=0.4.0:graphics/py-pycha@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
