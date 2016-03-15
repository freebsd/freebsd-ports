# $FreeBSD$

PORTNAME=	rtv
PORTVERSION=	1.8.1
CATEGORIES=	www

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Commandline client for reddit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=3.2:${PORTSDIR}/www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}praw>=3.4.0:${PORTSDIR}/www/py-praw \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}kitchen>=1.2.4:${PORTSDIR}/devel/py-kitchen

USE_GITHUB=	yes
GH_ACCOUNT=	michael-lazar
GH_TAGNAME=	201ef8e
USES=		tar:xz python:3.3+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
