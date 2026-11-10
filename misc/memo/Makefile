PORTNAME=	memo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	misc
PKGNAMESUFFIX=	-cli-tool

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI tool for managing Apple Notes and Apple Reminders
WWW=		https://antoniorodr.github.io/memo/ \
		https://github.com/antoniorodr/memo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=7.4.3:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.3.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>0:textproc/py-html2text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=3.3.3:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.7.0:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 noflavors autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	antoniorodr

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -o addopts=""

# tests as of 0.6.2: 23 passed in 0.08s

.include <bsd.port.mk>
