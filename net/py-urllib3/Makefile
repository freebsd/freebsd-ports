# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	urllib3
PORTVERSION=	1.15.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Enhance HTTP Python's standard library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi \
	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.0:net/py-pysocks

USES=	python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.pre.mk>

# ndg_httpclient is only available for Python 2
.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>=0.4.0:net/py-ndg_httpsclient
.endif

post-extract:
.if ${PYTHON_REL} >= 3000
	@${RM} ${WRKSRC}/urllib3/contrib/pyopenssl.py
.endif

.include <bsd.port.post.mk>
