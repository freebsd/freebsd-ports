PORTNAME=	napari
DISTVERSION=	0.8.0
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
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
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
		${PYTHON_PKGNAMEPREFIX}napari-svg>=0.1.8:misc/py-napari-svg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}npe2>=0.8.1:misc/py-npe2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=1.0.0:textproc/py-numpydoc@${PY_FLAVOR} \
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
		${PYTHON_PKGNAMEPREFIX}vispy>=0.16.2:graphics/py-vispy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.14.1:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent
# pytest intentionally omitted: the napari test suite requires a Qt/GUI
# display and a large optional dependency stack, so it cannot pass in a
# clean non-GUI environment.

NO_ARCH=	yes

.include <bsd.port.mk>
