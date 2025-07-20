PORTNAME=	nomadnet
DISTVERSION=	0.8.0
CATEGORIES=	net-p2p
MASTER_SITES=	PYPI

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Off-grid, resilient mesh communication
WWW=		https://github.com/markqvist/nomadnet

LICENSE=	GPLv3

RUN_DEPENDS=	lxmf>0:net-p2p/lxmf \
		${PYTHON_PKGNAMEPREFIX}qrcode>=0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=0:devel/py-urwid@${PY_FLAVOR} \
		reticulum>0:net-p2p/reticulum

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
