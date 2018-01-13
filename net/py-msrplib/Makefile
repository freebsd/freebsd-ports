# Created by: Eugene Grosbein <ports@grosbein.net>
# $FreeBSD$

PORTNAME=	msrplib
PORTVERSION=	0.19.0
CATEGORIES=	net python
MASTER_SITES=	http://download.ag-projects.com/MSRP/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python MSRP client library

LICENSE=	LGPL20+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}application>=1.2.8:devel/py-application@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlib>=0:devel/py-eventlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gnutls>=3.0.0:security/py-gnutls@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
