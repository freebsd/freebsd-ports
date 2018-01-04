# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydirector
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	SF/pythondirector/pythondirector/pythondirector-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	TCP load balancer written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:2.7

PORTDOCS=	*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
