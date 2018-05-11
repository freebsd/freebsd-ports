# $FreeBSD$

PORTNAME=	pywinrm
PORTVERSION=	0.3.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Python library for Windows Remote Management (WinRM)

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xmltodict>0:devel/py-xmltodict@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests_ntlm>=0.3.0:www/py-requests_ntlm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-kerberos>=0.10.0:security/py-requests-kerberos@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-credssp>=0.0.1:security/py-requests-credssp@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
