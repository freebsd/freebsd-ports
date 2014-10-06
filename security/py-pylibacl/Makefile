# Created by: joris
# $FreeBSD$

PORTNAME=	pylibacl
PORTVERSION=	0.5.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	Manipulate ACL with Python

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	COPYING NEWS README

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
