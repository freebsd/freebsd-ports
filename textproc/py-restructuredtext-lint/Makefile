PORTNAME=	restructuredtext-lint
DISTVERSION=	2.0.2
CATEGORIES=	textproc devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Linter for reStructuredText
WWW=		https://github.com/twolfson/restructuredtext-lint

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.11,1<1.0,1:textproc/py-docutils@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	twolfson
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
