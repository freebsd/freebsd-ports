# $FreeBSD$

PORTNAME=	ntfy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
CATEGORIES=	sysutils deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility for sending notifications on-demand, and when commands finish

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python:3.5+ # with python:2.7 devel/py-ruamel fails with missing ruamel.ordereddict which is marked as extra-dependency there for python-2.X only
USE_GITHUB=	yes
GH_ACCOUNT=	dschep
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
