PORTNAME=	python-dotenv
PORTVERSION=	1.1.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_dotenv-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add .env support to your django/flask apps
WWW=		https://github.com/theskumar/python-dotenv

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	rubygem-dotenv # bin/dotenv

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI
OPTIONS_DEFAULT=CLI
CLI_DESC=	Command-line interface support

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${PY_FLAVOR}

.include <bsd.port.mk>
