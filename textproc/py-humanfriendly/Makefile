# $FreeBSD$

PORTNAME=	humanfriendly
PORTVERSION=	4.4.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Human friendly output for text interfaces using Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}monotonic>0:devel/py-monotonic@${FLAVOR}
.endif

.include <bsd.port.post.mk>
