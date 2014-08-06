# Created by: Guixing Bai<khsing.cn@gmail.com>
# $FreeBSD$

PORTNAME=	tornado
PORTVERSION=	4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	khsing.cn@gmail.com
COMMENT=	Python Web Server from FriendFeed

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:${PORTSDIR}/security/py-certify

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.ssl_match_hostname>0:${PORTSDIR}/security/py-backports.ssl_match_hostname \
		${PYTHON_PKGNAMEPREFIX}futures>0:${PORTSDIR}/devel/py-futures
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m tornado.test.runtests

.include <bsd.port.post.mk>
