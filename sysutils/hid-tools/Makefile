PORTNAME=	hid-tools
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	sysutils python

MAINTAINER=	wulf@FreeBSD.org
COMMENT=	Python scripts to manipulate HID data
WWW=		https://gitlab.freedesktop.org/libevdev/hid-tools

LICENSE=	GPLv2

RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}parse>=0:textproc/py-parse@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyudev>=0:devel/py-pyudev@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
			${RUN_DEPENDS_${OPSYS}_${OSREL:R}}

USES=		python shebangfix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org/
GL_ACCOUNT=	libevdev
GL_TAGNAME=	0f71fd65d83b28b744a2fe0a6cc1e3139921c721
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pypandoc>=0:textproc/py-pypandoc@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
