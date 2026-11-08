PORTNAME=	relatorio
PORTVERSION=	1.0.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Templating library able to output odt files
WWW=		https://docs.tryton.org/relatorio/latest/ \
		https://github.com/tryton/relatorio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-tryton>=0:devel/py-hatch-tryton@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:textproc/py-genshi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.0:devel/py-lxml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

SHEBANG_FILES=	relatorio/render.py

OPTIONS_DEFINE=	FODT
OPTIONS_DEFAULT=FODT
FODT_DESC=	OpenDocument support

FODT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}puremagic>=0:sysutils/py-puremagic@${PY_FLAVOR}

.include <bsd.port.mk>
