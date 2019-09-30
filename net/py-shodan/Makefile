# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shodan
PORTVERSION=	1.19.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Python library and command-line utility for Shodan

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}XlsxWriter>0:textproc/py-xlsxwriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>=1.0.3:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=3.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.2.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
