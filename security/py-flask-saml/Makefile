# Created by: John W. O'Brien <john@saltant.com>
# $FreeBSD$

PORTNAME=	Flask-SAML
PORTVERSION=	0.4.3
CATEGORIES=	security www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	SAML authentication for Flask web apps

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>0.8.0:www/py-flask@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.1:devel/py-blinker@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>4.0.0:security/py-pysaml2@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
