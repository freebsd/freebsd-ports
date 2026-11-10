PORTNAME=	napari
DISTVERSION=	0.10.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	N-dimensional array viewer in Python
WWW=		https://napari.org/stable/ \
		https://github.com/napari/napari

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}app-model>=0.5.0:devel/py-app-model@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachey>=0.2.1:devel/py-cachey@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2018.1.18:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=2022.1.1:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>=2.20:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.2.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.3:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}magicgui>=0.7.0:x11-toolkits/py-magicgui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari-console>=0.1.4:graphics/py-napari-console@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari-plugin-engine>=0.2.1:graphics/py-napari-plugin-engine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari-resources>=1.0.1:misc/py-napari-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari-svg>=0.1.8:misc/py-napari-svg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}npe2>=0.10.0:misc/py-npe2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.5.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.17:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.3.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.4:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psygnal>=0.14.2:devel/py-psygnal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.8.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-extra-types>0:devel/py-pydantic-extra-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.13.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=3.1.10:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.4.0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.20.0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.14.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}superqt>=0.7.8:x11-toolkits/py-superqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tifffile>=2022.7.28:graphics/py-tifffile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=0.12.1:devel/py-toolz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.56.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vispy>=0.17.0:graphics/py-vispy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.14.1:devel/py-wrapt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.9.0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.15:textproc/py-docstring_parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2023.10.0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.8.0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.25.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml-html-clean>0:devel/py-lxml-html-clean@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.6.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pooch>=1.6.0:devel/py-pooch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pretend>=1.0.9:devel/py-pretend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-pretty>=1.1.0:devel/py-pytest-pretty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-qt>=4.4.0:devel/py-pytest-qt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=15.1:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qtconsole>=5.4.0:devel/py-qtconsole@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=14.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.24.7:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2023.5.0:devel/py-xarray@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zarr>=3.0.8:devel/py-zarr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} QT_QPA_PLATFORM=offscreen
TEST_WRKSRC=	${WRKSRC}/src/napari
# Ignored: Qt/vispy/viewer tests need OpenGL (no GPU/GL here: they segfault or fail on the offscreen
# platform), test_tips needs network, shapes tests lack fixtures from the ignored conftest files
TEST_ARGS=	--disable-plugin-autoload \
		-p rerunfailures \
		-p pytestqt \
		-p pytestqt.plugin \
		-p npe2._pytest_plugin \
		-p napari.utils._testsupport \
		-p napari.conftest \
		-o strict_markers=false \
		--noconftest \
		--ignore=napari/_qt \
		--ignore=napari/_vispy \
		--ignore=napari/_tests/test_adding_removing.py \
		--ignore=napari/_tests/test_advanced.py \
		--ignore=napari/_tests/test_cli.py \
		--ignore=napari/_tests/test_conftest_fixtures.py \
		--ignore=napari/_tests/test_function_widgets.py \
		--ignore=napari/_tests/test_key_bindings.py \
		--ignore=napari/_tests/test_layer_utils_with_qt.py \
		--ignore=napari/_tests/test_magicgui.py \
		--ignore=napari/_tests/test_mouse_bindings.py \
		--ignore=napari/_tests/test_multiple_viewers.py \
		--ignore=napari/_tests/test_pytest_plugin.py \
		--ignore=napari/_tests/test_view_layers.py \
		--ignore=napari/_tests/test_viewer.py \
		--ignore=napari/_tests/test_windowsettings.py \
		--ignore=napari/_tests/test_notebook_display.py \
		--ignore=napari/layers/shapes/_tests/test_shapes.py \
		--ignore=napari/layers/shapes/_tests/test_shapes_utils.py \
		--ignore=napari/utils/_tests/test_tips.py

do-test:
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest ${TEST_ARGS} napari

# tests as of 0.10.0: 3506 passed, 158 skipped, 1 xfailed (Qt/vispy/viewer tests are ignored because they need OpenGL and a display, test_tips needs network; no indication that anything is wrong with this package)

.include <bsd.port.mk>
