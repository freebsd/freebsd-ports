PORTNAME=	s-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-2
DISTVERSIONSUFFIX=	-gfb91ef6
CATEGORIES=	sysutils python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stress Terminal UI: stress test and monitoring tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.6.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.0.1:devel/py-urwid@${PY_FLAVOR}

USES=		python pytest
USE_GITHUB=	yes
GH_ACCOUNT=	amanusk
USE_PYTHON=	distutils noflavors autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
