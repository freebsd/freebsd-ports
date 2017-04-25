# $FreeBSD$

PORTNAME=	humanfriendly
PORTVERSION=	2.4
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Human friendly output for text interfaces using Python

LICENSE=	MIT

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} == "2"
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}monotonic>0:devel/py-monotonic
.endif

.include <bsd.port.post.mk>
