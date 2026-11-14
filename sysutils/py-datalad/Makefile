PORTNAME=	datalad
DISTVERSION=	1.8.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed data management system
WWW=		https://www.datalad.org \
		https://github.com/datalad/datalad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fasteners>=0.14:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}looseversion>0:devel/py-looseversion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=59.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		git:devel/git
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}annexremote>0:devel/py-annexremote@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0.4:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.14:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}giturlparse>0:devel/py-giturlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>0:devel/py-humanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=20.0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyrings.alt>0:security/py-keyrings.alt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}looseversion>0:devel/py-looseversion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patool>=1.7:archivers/py-patool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gitlab>0:devel/py-python-gitlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.32.0:misc/py-tqdm@${PY_FLAVOR} \
		git:devel/git
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpretty>=0.9.4:www/py-httpretty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-retry>0:devel/py-pytest-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>0:devel/py-vcrpy@${PY_FLAVOR}
py311_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# archive tests fail with patool/tar exit status 100, test_pytest_plugin.py
# needs the installed datalad pytest plugin, the rest depends on the environment
TEST_ARGS=	--disable-plugin-autoload -p pytest_retry.retry_plugin \
		--deselect datalad/core/local/tests/test_resulthooks.py::test_basics \
		--deselect datalad/customremotes/tests/test_archives.py::test_annex_get_from_subdir \
		--deselect datalad/customremotes/tests/test_archives.py::test_basic_scenario \
		--deselect datalad/downloaders/tests/test_credentials.py::test_delete_not_crashing \
		--deselect datalad/local/tests/test_download_url.py::test_download_url_archive \
		--deselect datalad/local/tests/test_download_url.py::test_download_url_archive_from_subdir \
		--deselect datalad/local/tests/test_download_url.py::test_download_url_archive_trailing_separator \
		--deselect datalad/local/tests/test_gitcredential.py::test_datalad_credential_helper \
		--deselect datalad/local/tests/test_wtf.py::test_wtf \
		--deselect datalad/support/tests/test_locking.py::test_try_lock_informatively \
		--deselect datalad/support/tests/test_openfiles.py::test_cli_detects_open_file \
		--deselect datalad/support/tests/test_openfiles.py::test_get_files_open_for_writing \
		--deselect datalad/tests/test_utils.py::test_get_open_files \
		--deselect datalad/tests/test_utils.py::test_md5sum_archive \
		--deselect datalad/local/tests/test_add_archive_content.py \
		--deselect datalad/tests/test_archives.py \
		--deselect datalad/tests/test_pytest_plugin.py

# tests as of 1.8.0: 1292 passed, 106 skipped, 70 deselected, 3 xfailed, 1 xpassed, 42 warnings in 2861.61s (0:47:41)

.include <bsd.port.mk>
