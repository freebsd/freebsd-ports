PORTNAME=	elf_diff
DISTVERSIONPREFIX=v
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Tool to Compare Elf Binaries
WWW=		https://github.com/noseglasses/elf_diff

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>0:devel/py-setuptools-git@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}progressbar2>0:misc/py-progressbar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anytree>0:devel/py-anytree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dict2xml>0:textproc/py-dict2xml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deepdiff>0:devel/py-deepdiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		git:devel/git

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	noseglasses

BINARY_ALIAS=	objdump=llvm-objdump
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} tests/test_main.py

.include <bsd.port.mk>
