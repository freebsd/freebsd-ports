# Created by: Eugene Grosbein <ports@grosbein.net>
# $FreeBSD$

PORTNAME=	msrplib
PORTVERSION=	0.14.4
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://download.ag-projects.com/SipClient/ \
		http://www.grosbein.net/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python MSRP client library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}application>=1.1.0:devel/py-application@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.9.15:net/py-eventlet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gnutls>=1.1.6:security/py-gnutls@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
