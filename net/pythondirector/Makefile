# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydirector
PORTVERSION=	1.0.0
CATEGORIES=	net python
MASTER_SITES=	SF/pythondirector/pythondirector/pythondirector-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP load balancer written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PORTDOCS=		*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
