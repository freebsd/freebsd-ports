# $FreeBSD$

PORTNAME=	Flask-OAuthlib
PORTVERSION=	0.9.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	OAuthlib for Flask

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>0:${PORTSDIR}/www/py-flask \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:${PORTSDIR}/security/py-oauthlib \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>0:${PORTSDIR}/www/py-requests-oauthlib

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
