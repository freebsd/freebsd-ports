# $FreeBSD$

PORTNAME=	s-tui
DISTVERSION=	0.8.2
CATEGORIES=	sysutils python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Stress Terminal UI: stress test and monitoring tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.2.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.3.1:devel/py-urwid@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	amanusk
GH_TAGNAME=	200c8f1 # experimental free_bsd branch
USE_PYTHON=	distutils noflavors autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
