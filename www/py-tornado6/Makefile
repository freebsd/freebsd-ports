# Created by: Guixing Bai <khsing.cn@gmail.com>
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	6.0.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Web Server from FriendFeed

LICENSE=	APACHE20

CONFLICTS=	py[0-9]*-tornado-* py[0-9]*-tornado4-*

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

post-build:
	@${FIND} ${WRKSRC}/build -name speedups.so -exec ${STRIP_CMD} {} \;

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.mk>
