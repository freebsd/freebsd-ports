# $FreeBSD$

PORTNAME=	gntp
PORTVERSION=	0.8
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Growl Notification Transport Protocol for Python

LICENSE=	MIT

GH_ACCOUNT=	kfdm

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${FLAVOR}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
