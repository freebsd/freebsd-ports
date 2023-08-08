PORTNAME=	rich-cli
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command Line Interface to Rich
WWW=		https://github.com/Textualize/rich-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0.0<9.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich12>=12.4.1<13.0.0:textproc/py-rich12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-rst>=1.1.7<2.0.0:textproc/py-rich-rst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textual>=0.1.18<0.2.0:textproc/py-textual@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
