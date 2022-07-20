PORTNAME=	rpy2
PORTVERSION=	3.5.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the R Programming Language

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.10.0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libR.so:math/R \
		libicui18n.so:devel/icu \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.10.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0,1,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=0:devel/py-tzlocal@${PY_FLAVOR}

USES=		compiler:c11 fortran python:3.7+ readline
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	RPY2_CFFI_MODE=BOTH

PLIST_FILES=	${PYTHON_SITELIBDIR}/__pycache__/_rinterface_cffi_abi.cpython-${PYTHON_SUFFIX}.opt-1.pyc \
		${PYTHON_SITELIBDIR}/__pycache__/_rinterface_cffi_abi.cpython-${PYTHON_SUFFIX}.pyc \
		${PYTHON_SITELIBDIR}/_rinterface_cffi_abi.py

OPTIONS_DEFINE=	NUMPY PANDAS
OPTIONS_DEFAULT=NUMPY PANDAS
NUMPY_DESC=	NumPy support
PANDAS_DESC=	Pandas support

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0,1:math/py-pandas@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>=0,1:math/py-pandas@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
