PORTNAME=	pelican
PORTVERSION=	4.8.0
CATEGORIES=	www textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andreas@bilke.org
COMMENT=	Static site generator written in Python
WWW=		https://docs.getpelican.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=1.4:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.16:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedgenerator>=1.9:www/py-feedgenerator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.6:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=10.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=1.1:converters/py-unidecode@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.9:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8-import-order>=0.18:devel/py-flake8-import-order@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.8:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}invoke>=1.3:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=5.2:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.3:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>2.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typogrify>=2.0:textproc/py-typogrify@${PY_FLAVOR} \
		git>0:devel/git \
		hs-pandoc>:textproc/hs-pandoc

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	getpelican
USE_PYTHON=	autoplist concurrent distutils pytest

SHEBANG_FILES=	pelican/tools/*.py \
		pelican/tools/templates/pelicanconf.py.jinja2 \
		pelican/tools/templates/publishconf.py.jinja2
NO_ARCH=	yes

.include <bsd.port.pre.mk>

PYTEST_BROKEN_TESTS=	test_basis_generation_works \
			test_custom_generation_works \
			test_custom_locale_generation_works

.include <bsd.port.post.mk>
