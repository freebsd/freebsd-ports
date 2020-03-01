# Created by: Guixing Bai <khsing.cn@gmail.com>
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	4.5.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Web Server from FriendFeed

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}tornado \
			${PYTHON_PKGNAMEPREFIX}tornado6

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>0:devel/py-singledispatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports_abc>=0.4:devel/py-backports_abc@${PY_FLAVOR}
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/tornado/speedups.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.post.mk>
