PORTNAME=	hid-tools
DISTVERSION=	0.8
CATEGORIES=	sysutils python

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Python scripts to manipulate HID data
WWW=		https://gitlab.freedesktop.org/libevdev/hid-tools

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypandoc>=0:textproc/py-pypandoc@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse>=0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyudev>=0:devel/py-pyudev@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python shebangfix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org/
GL_ACCOUNT=	libevdev
USE_PYTHON=	autoplist pep517

python_OLD_CMD=	"/bin/env python3"
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
