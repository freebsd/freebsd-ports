# Created by: Guixing Bai <khsing.cn@gmail.com>

PORTNAME=	tornado
PORTVERSION=	6.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Web Server from FriendFeed

LICENSE=	APACHE20

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}tornado4 \
			${PYTHON_PKGNAMEPREFIX}tornado5 \
			${PYTHON_PKGNAMEPREFIX}tornado6

CPE_VENDOR=	tornadoweb

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.mk>
