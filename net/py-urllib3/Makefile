# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	urllib3
PORTVERSION=	1.16
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Enhance HTTP Python's standard library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi \
	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.7:net/py-pysocks \
	${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>=0.4.1:net/py-ndg_httpsclient

USES=	python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.pre.mk>

post-extract:
.if ${PYTHON_REL} >= 3000
	@${RM} ${WRKSRC}/urllib3/contrib/pyopenssl.py
.endif

.include <bsd.port.post.mk>
