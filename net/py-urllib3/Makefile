# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	urllib3
PORTVERSION=	1.9
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Enhance HTTP Python's standard library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

# ndg_httpclient is only available for Python 2
.if ${PYTHON_REL} < 300
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>=0.3.2:${PORTSDIR}/net/py-ndg_httpsclient
PLIST_SUB+=	SSL=""
.else
PLIST_SUB+=	SSL="@comment "
.endif

post-extract:
.if ${PYTHON_REL} >= 300
	@${RM} ${WRKSRC}/urllib3/contrib/pyopenssl.py
.endif

.include <bsd.port.post.mk>
