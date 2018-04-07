# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	softlayer
PORTVERSION=	5.4.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SoftLayer-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SoftLayer API Python Client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0.7.0:devel/py-prettytable@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=0.53:devel/py-prompt_toolkit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0.0:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.22:net/py-urllib3@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
