PORTNAME=	language-tags
DISTVERSION=	1.3.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IANA language tags in Python
WWW=		https://github.com/OnroerendErfgoed/language-tags

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 1.3.2: 74 passed in 0.06s

.include <bsd.port.mk>
