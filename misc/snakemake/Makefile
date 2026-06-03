PORTNAME=	snakemake
DISTVERSION=	9.20.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Workflow management system
WWW=		https://github.com/snakemake/snakemake

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}conda-inject>=1.3.1:devel/py-conda-inject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>0:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}connection_pool>=0.0.3:devel/py-connection_pool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dpath>=2.1.6:devel/py-dpath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanfriendly>0:textproc/py-humanfriendly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}immutables>0:devel/py-immutables@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PuLP>=2.3.1:math/py-PuLP@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}referencing>0:devel/py-referencing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.8.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smart-open>=4.0:net/py-smart-open@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-common>=1.20.1:misc/py-snakemake-interface-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-executor-plugins>=9.3.2:misc/py-snakemake-interface-executor-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-logger-plugins>=1.1.0:misc/py-snakemake-interface-logger-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-report-plugins>=1.2.0:misc/py-snakemake-interface-report-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-scheduler-plugins>=2.0.0:misc/py-snakemake-interface-scheduler-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-storage-plugins>=4.4.1:misc/py-snakemake-interface-storage-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlmodel>=0.0.37:databases/py-sqlmodel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.1.4:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}throttler>0:devel/py-throttler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>0:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yte>=1.5.5:textproc/py-yte@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		tests/test_args.py tests/test_internals.py tests/test_io.py \
		tests/test_prefix_lookup.py -v

NO_ARCH=	yes

# tests as of 9.20.0: 20 passed in 2.94s

.include <bsd.port.mk>
