PORTNAME=	hid-tools
PORTVERSION=	0.2
CATEGORIES=	sysutils python
MASTER_SITES=	https://gitlab.freedesktop.org/libevdev/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Python scripts to manipulate HID data

LICENSE=	GPLv2

RUN_DEPENDS_FreeBSD_12=	iichid>=0.0.6:sysutils/iichid
RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}parse>=0:textproc/py-parse@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyudev>=0:devel/py-pyudev@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
			${RUN_DEPENDS_${OPSYS}_${OSREL:R}}

USES=		python:3.6+ shebangfix tar:bz2
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pypandoc>=0:textproc/py-pypandoc@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
