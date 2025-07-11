PORTNAME=	dict2xml
DISTVERSIONPREFIX=release-
DISTVERSION=	1.7.7
CATEGORIES=	textproc devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Small utility to convert a python dictionary into an XML string
WWW=		https://github.com/delfick/python-dict2xml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}noseofyeti>0:devel/py-noseofyeti@${PY_FLAVOR}

USES=		python
#doesnt ship tests in sdist
USE_GITHUB=	yes
USE_PYTHON=	autoplist pep517

GH_ACCOUNT=	delfick
GH_PROJECT=	python-dict2xml

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
