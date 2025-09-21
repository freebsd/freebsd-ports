PORTNAME=	napari
DISTVERSION=	0.6.4
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	n-dimensional array viewer in Python
WWW=		https://napari.org/stable/ \
		https://github.com/napari/napari

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=9.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=3.1.5:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}app-model>=0.4.0:devel/py-app-model@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.4:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachey>=0.2.1:devel/py-cachey@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2018.1.18:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=2021.10.0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>=2.20:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.2.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.3:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}magicgui>=0.7.0:x11-toolkits/py-magicgui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari-console>=0.1.1:graphics/py-napari-console@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari-plugin-engine>=0.1.9:graphics/py-napari-plugin-engine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari-svg>=0.1.8:misc/py-napari-svg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}npe2>=0.7.9:misc/py-npe2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=1.0.0:textproc/py-numpydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.3.3:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.17:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psygnal>=0.10.0:devel/py-psygnal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.6.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qtpy>=2.3.1:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.19.1:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}superqt>=0.7.4:x11-toolkits/py-superqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tifffile>=2022.7.28:graphics/py-tifffile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=0.11.0:devel/py-toolz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.56.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vispy>=0.15.2:graphics/py-vispy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.13.3:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.mk>
