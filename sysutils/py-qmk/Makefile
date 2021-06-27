PORTNAME=	qmk
DISTVERSION=	0.1.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	CLI program for working with QMK firmware

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dotty-dict>=0:devel/py-dotty-dict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hid>=0:comms/py-hid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hjson>=0:textproc/py-hjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}milc>=1.4.0:devel/py-milc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose2>=0:devel/py-nose2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>=0:textproc/py-yapf@${PY_FLAVOR} \
		arm-none-eabi-gcc>0:devel/arm-none-eabi-gcc \
		avr-gcc>0:devel/avr-gcc \
		avr-libc>0:devel/avr-libc \
		avrdude>0:devel/avrdude \
		dfu-programmer>0:comms/dfu-programmer \
		dfu-util>0:comms/dfu-util \
		git:devel/git

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_GLOB=	*.py

TEST_ENV=	PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}"
TEST_TARGET=	config
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/qmk

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>
