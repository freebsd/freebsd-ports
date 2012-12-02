# Created by: Guixing Bai<khsing.cn@gmail.com>
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	2.4.1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	khsing.cn@gmail.com
COMMENT=	Python Web Server from FriendFeed

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	50af6cc

USE_PYTHON=		2.5-2.7
USE_PYDISTUTILS=	easy_install

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.mk>
