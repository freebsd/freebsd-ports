PORTNAME=	s-tui
PORTVERSION=	1.5.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
DISTNAME=	s_tui-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stress Terminal UI, Terminal-based CPU stress and monitoring utility
WWW=		https://github.com/amanusk/s-tui

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=7.0.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=3.0.2:devel/py-urwid@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>
