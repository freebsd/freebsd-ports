# Created by: Eugene Grosbein <ports@grosbein.net>
# $FreeBSD$

PORTNAME=	msrplib
PORTVERSION=	0.20.0
CATEGORIES=	net python
MASTER_SITES=	http://download.ag-projects.com/MSRP/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python MSRP client library

LICENSE=	LGPL21+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}application>=1.2.8:devel/py-application@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlib>=0:devel/py-eventlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gnutls>=3.0.0:security/py-gnutls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
