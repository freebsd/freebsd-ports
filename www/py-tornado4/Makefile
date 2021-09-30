# Created by: Guixing Bai <khsing.cn@gmail.com>

PORTNAME=	tornado
PORTVERSION=	4.5.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Web Server from FriendFeed

LICENSE=	APACHE20

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	tornadoweb

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}tornado \
			${PYTHON_PKGNAMEPREFIX}tornado6

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/tornado/speedups*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.mk>
