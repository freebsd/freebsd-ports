PORTNAME=	qiskit-nature
DISTVERSION=	0.6.2
CATEGORIES=	science python # quantum-computing, quantum-chemistry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Natural science submodule for Quiskit framework for quantum computing
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.21.0:science/py-qiskit-terra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rustworkx>=0.10.1:math/py-rustworkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
QC_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyscf>0:science/py-pyscf@${PY_FLAVOR} # quantum-chemistry drivers, other supported drivers are PyQuante, PSI4
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS} \
		${QC_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ddt>0:devel/py-ddt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} # also threadctl is required but it is currently broken on FreeBSD

USES=		python
USE_PYTHON=	distutils autoplist pytest # several tests fail with "No module named 'threadpoolctl'", see https://reviews.freebsd.org/D35513

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

NO_ARCH=	yes

POST_PLIST=	fix-plist

post-patch: # project was renamed, see https://github.com/Qiskit/rustworkx/issues/656
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|retworkx|rustworkx|'

post-install: # installs many binaries accessing commercial Gaussian software not available on FreeBSD, see https://github.com/Qiskit/qiskit-nature/issues/778
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "qcmatrixio.cpython-*.so" -delete

fix-plist: # see post-install
	@${REINPLACE_CMD} -e "s|.*/qcmatrixio\.cpython-.*\.so$$||" ${TMPPLIST}

.include <bsd.port.mk>
