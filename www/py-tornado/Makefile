# Created by: Guixing Bai<khsing.cn@gmail.com>
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	3.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	khsing.cn@gmail.com
COMMENT=	Python Web Server from FriendFeed

LICENSE=	APACHE20

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 300
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.post.mk>
