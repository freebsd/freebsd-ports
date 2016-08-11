# $FreeBSD$

PORTNAME=	rtv
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Commandline client for reddit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=3.2:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}praw>=3.4.0:www/py-praw \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.2:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}kitchen>=1.2.4:devel/py-kitchen

USE_GITHUB=	yes
GH_ACCOUNT=	michael-lazar
USES=		tar:xz python:3.3+
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
