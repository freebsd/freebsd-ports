# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tweepy
PORTVERSION=	3.3.0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTVERSIONPREFIX=	v

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Twitter API library for Python!

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:${PORTSDIR}/devel/py-pip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.4.1:${PORTSDIR}/www/py-requests-oauthlib \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.3:${PORTSDIR}/devel/py-six

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
