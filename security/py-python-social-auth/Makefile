# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-social-auth
PORTVERSION=	0.2.14
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Python Social Auth is a social authentication/registration mechanism

RUN_DEPENDS:=	py-python-openid>=2.2:${PORTSDIR}/security/py-python-openid \
		py-requests>=2.5.1:${PORTSDIR}/www/py-requests \
		py-oauthlib>=0.3.8:${PORTSDIR}/security/py-oauthlib \
		py-requests-oauthlib>=0.3.1:${PORTSDIR}/www/py-requests-oauthlib \
		py-six>=1.2.0:${PORTSDIR}/devel/py-six \
		py-pyjwt>=1.0.0:${PORTSDIR}/www/py-pyjwt

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
