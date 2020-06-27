# $FreeBSD$

PORTNAME=	plover
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://launchpadlibrarian.net/88624187/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Open source solution for stenography

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>=0:x11-toolkits/py-xlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0:devel/py-lockfile@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils
USE_WX=		3.0+
WX_COMPS=	wx

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
