# $FreeBSD$

PORTNAME=	s-tui
DISTVERSION=	0.6.7.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Stress Terminal UI - stress test and monitoring tool

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>0:devel/py-urwid@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
