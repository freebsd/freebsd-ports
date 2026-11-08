PORTNAME=	subliminal
DISTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Python library to search and download subtitles
WWW=		https://subliminal.readthedocs.org/en/latest/index.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfish>=0.6.1:devel/py-babelfish@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.4.0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=5.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-option-group>=0.5.6:devel/py-click-option-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=1.0:devel/py-dogpile.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}guessit>=3.0.0:multimedia/py-guessit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}knowit>=0.5.5:multimedia/py-knowit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=3:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysubs2>=1.7:multimedia/py-pysubs2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rarfile>=2.7:archivers/py-rarfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}srt>=3.5:multimedia/py-srt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=3.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.13.2:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}knowit>=0.5.5:multimedia/py-knowit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>0:devel/py-vcrpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
