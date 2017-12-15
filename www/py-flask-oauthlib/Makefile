# $FreeBSD$

PORTNAME=	Flask-OAuthlib
PORTVERSION=	0.9.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	OAuthlib for Flask

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:security/py-oauthlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>0:www/py-requests-oauthlib@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
