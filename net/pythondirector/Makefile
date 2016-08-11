# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydirector
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	SF/pythondirector/pythondirector/pythondirector-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP load balancer written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

USES=		python twisted:run
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
