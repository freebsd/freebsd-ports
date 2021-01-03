# Created by: Guixing Bai <khsing.cn@gmail.com>
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	5.1.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Web Server from FriendFeed

LICENSE=	APACHE20

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}tornado4 \
			${PYTHON_PKGNAMEPREFIX}tornado6

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/tornado/speedups*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.mk>
