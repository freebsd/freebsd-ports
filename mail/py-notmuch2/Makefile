CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

COMMENT=	Pythonic bindings for the notmuch mail database using CFFI

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libnotmuch.so:mail/notmuch

USES=		python:3.5+ uniquefiles:dirs
USE_PYTHON=	autoplist distutils

MASTERDIR=	${.CURDIR}/../notmuch
WRKSRC_SUBDIR=	bindings/python-cffi

PORTSCOUT=	limit:^[0-9\.]*$$

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/notmuch2/_capi.abi3*.so

.include "${MASTERDIR}/Makefile"
