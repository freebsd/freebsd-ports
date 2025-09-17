PORTNAME=	nikola
DISTVERSION=	8.3.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Modular, fast, simple, static website and blog generator
WWW=		https://getnikola.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=60.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0:devel/py-installer@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=1.3:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}doit>=0.33.1:devel/py-doit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.4.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.1.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.19:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=1.0.9:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.4.16:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrss2gen>=1.1:textproc/py-pyrss2gen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.5.2:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=5.1.0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}piexif>=1.0.3:graphics/py-piexif@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.12.0:devel/py-babel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.7.7:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0.3.10:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.10:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>=6.3.0:devel/py-pydocstyle@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

SHEBANG_FILES=	docs/sphinx/update-modules.sh \
		scripts/update-npm-assets.sh \
		scripts/generate_symlinked_list.sh \
		scripts/baseline.sh \
		scripts/capty

OPTIONS_DEFINE=	EXTRAS
OPTIONS_DEFAULT=EXTRAS
EXTRAS_DESC=	Install extras modules

EXTRAS_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyphen>=0.9.1:textproc/py-pyphen@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typogrify>=2.0.4:textproc/py-typogrify@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}phpserialize>=1.3:devel/py-phpserialize@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}notebook>=6.0.0:www/py-notebook@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ipykernel>=6.21.2:devel/py-ipykernel@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ghp-import>=1.0.0:www/py-ghp-import@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.6:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}watchdog>=2.3.0:devel/py-watchdog@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15.98:devel/py-ruamel.yaml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}toml>=0.9.2:textproc/py-toml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5lib>=1.0.1:www/py-html5lib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}hsluv>=5.0.0:graphics/py-hsluv@${PY_FLAVOR}

.include <bsd.port.pre.mk>

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.post.mk>
